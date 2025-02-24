### 11437번: LCA

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/11437)
2. **도움 블로그** : 
    - https://tarra.tistory.com/entry/%EB%B0%B1%EC%A4%80-11437%EB%B2%88-LCA-C
    - https://konkukcodekat.tistory.com/116

**문제 조건**
- N개의 정점으로 이루어진 트리, 루트는 1번

**출력**  
- M개의 줄에 차례대로 입력받은 두 노드의 **가장 가까운 공통 조상**을 출력

### 풀이
1. 입력받은 간선에서 두 노드 중 어느 것이 부모 노드인지 모르므로, 각 노드에 방문할 수 있는 노드로 추가
2. _BFS_ 를 통해서 1번 노드부터 시작하여 각각 방문하여 각 노드의 `parents`, `depth`를 파악
3. 입력받은 M개의 각각의 두 노드 쌍을 `node_a`, `node_b`로 설정
4. 두 노드의 `depth`가 다를 시에 `node_b`를 더 깊은 노드 값으로 설정
5. `node_b`가 `node_a`의 `depth`가 될 때까지 부모 노드로 이동
6. 두 노드의 깊이가 같으면은 이제 각각 노드의 부모 노드로 이동하면서 **서로 같은 노드**를 가리킬 때까지 반복
7. 최종적으로 구한 노드는 `node_a`, `node_b` 둘 다 같은 노드를 가리키므로 두개 중 아무거나 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```py
def bfs(node):
    dq = deque()
    dq.append(node)
    
    while dq:
        node = dq.popleft()
        vis[node] = True
        
        for next_node in edge[node]:
            if vis[next_node]:
                continue
            parents[next_node] = node
            depth[next_node] = depth[node] + 1
            dq.append(next_node)
```
- `dq`에 `deque`를 선언후, 시작 노드를 추가
- `node` 값에 `dq`의 앞의 값을 꺼낸 후, 해당 노드를 방문 처리
- 해당 `node`로 부터 방문할 수 있는 노드들에서 이미 방문했던 노드는 제외
- 아직 방문하지 않은 노드의 `parents[]` 는 현재 노드 값, `depth[]`는 현재 노드의 깊이에 + 1 한 값
- `dq`에 다음 노드를 추가하여 루트 노드를 제외한 노드들의 `parents` 값과 `depth` 값을 파악

```py
def lca(node_a, node_b):
    if depth[node_a] > depth[node_b]:
        node_a, node_b = node_b, node_a
    
    while depth[node_a] != depth[node_b]:
        node_b = parents[node_b]

    while node_a != node_b:
        node_a = parents[node_a]
        node_b = parents[node_b]
        
    return node_a
```
- 입력 받은 `node_a`, `node_b` 값의 `depth`가 서로 다를 때 `node_b` 값의 깊이를 더 높은 것으로 노드들을 서로 교환
- `node_a`, `node_b` 의 `depth`가 서로 같아질 때까지 `node_b`를 부모 노드로 이동
- 이후, `node_a`, `node_b`가 서로 같은 노드를 가리킬 때까지 각각 서로 부모 노드로 이동
- 최종적으로 `node_a`와 `node_b`가 같은 노드 값을 가리키므로 가장 **가까운 공통 조상 노드**를 찾으므로 두 노드중 하나의 값을 반환
</details>

### 후기
- 내 코드로는 1000ms 정도가 발생하는데 다른 사람들은 30ms 코드가 있는데 정확한 원리는 잘 모르겠음
- py은 pypy로 컴파일해서 진행해야 해결할 수 있었으며, _DFS_ 로 하면 메모리 초과가 발생되어 _BFS_ 로 해결해야 했음