### 1761번: 정점들의 거리

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1761)
2. **도움 블로그** : https://winterflower.tistory.com/369

**문제 조건**
- N개의 정점으로 이루어진 트리와 N-1개의 간선이 주어짐

**출력**  
- M개의 두 노드 쌍을 입력받았을 때, 두 노드 사이의 거리를 출력

### 풀이
1. 일반적인 가중치가 있는 트리의 노드 쌍의 최소 거리는 _Dijstra_ 알고리즘으로 생각되지만, 이 경우는 좀 다르다.
2. _Dijstra_ 알고리즘은 두 노드 간의 이동할 수 있는 경로가 여러가지 일 때 그 중 최단 경로를 알 수 있지만, 현 트리는 임의의 노드 쌍에 한 간선밖에 없다.
3. 즉, 두 노드 쌍에 갈 수 있는 경로는 단 1개이므로, 현 문제에서 최악의 테스트 케이스(39,999 * 10,000)로 하면 시간초과 발생
4. 따라서, _LCA_ 를 통해 두 노드이 최소 공통 조상을 찾아서 해당 거리를 파악
5. 1번 노드를 최고 조상으로 놓고, 각각의 노드 도착 거리를 **누적 합으로 합산**
6. 두 노드의 쌍을 입력받았을 때, 처음 두 노드의 각 누적된 합을 더한 후에, 최소 공통 조상을 찾는다.
7. **최소 공통 조상의 누적 합 X 2** 값을 처음 누 노드의 합에 뺀다. (처음 두 노드에 이미 공통 조상의 누적 합이 있는 것이므로 뺌)
8. 위 과정을 통해서 _Dijstra_ 에 비해 빠르게 두 노드 사이의 거리를 알 수 있음

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void dfs(int node, int dep, int len) {
    vis[node] = true;
    depth[node] = dep;
    dist[node] = len;
    
    for(int i = 0; i < (int)edge[node].size(); i++) {
        int next_node = edge[node][i].X;
        int next_len = len + edge[node][i].Y;
        if(!vis[next_node]) {
            parents[next_node] = node;
            dfs(next_node, dep + 1, next_len);
        }
    }
}
```
- _c++의 경우, DFS 나 BFS 나 시간적으론 비슷_
- _DFS_ 를 통해 각 노드의 `depth`, 1번 노드로 부터의 가중치들의 합인 `len`을 대입
- `next_len` 은 부모 노드와의 가중치에 1번 노드와 부모 노드 사이 거리인 `len`을 합해서 다음 노드까지의 **누적된 가중치 거리**를 저장
- 위 과정을 반복하여 각 노드의 `dist[]`, `depth[]`, `parents[]`에 값을 저장

```cpp
int lca(int node_a, int node_b) {
    int len_a = dist[node_a], len_b = dist[node_b];
    
    if(depth[node_a] > depth[node_b]) swap(node_a, node_b);
    
    while(depth[node_a] != depth[node_b]) {
        node_b = parents[node_b];
    }
    
    while(node_a != node_b) {
        node_a = parents[node_a];
        node_b = parents[node_b];
    }
    
    return len_a + len_b - 2 * dist[node_a];
}
```
- 두 노드 사이의 거리를 구하는 함수로 `len_a`, `len_b` 는 각각 `node_a`, `node_b`가 1번 노드로 부터 얼만큼 거리에 있는지 저장
- 두 노드의 `depth`가 다를 시에 `node_b`의 깊이를 더 깊게 하기 위해 두 노드의 값을 변경
- 두 노드의 `depth`가 같을 때 까지 `depth[node_b]` 을 `depth[node_a]` 만큼 올림
- 두 노드의 최소 공통 조상을 구할 때까지 각각 노드의 부모 노드를 따라 올라감
- 최종적으로 구한 공통 조상인 `node_a`(=node_b)를 구함 
- 처음의 `len_a`와 `len_b` 더한 후, 구한 최소 공통 조상의 거리에 * 2한 만큼을 뺀 값을 반환  
_(두 노드에 각각 최소 공통 조상 누적 거리가 있으므로, 각각에 뺌으로써 두 노드 사이의 거리만 남음)_
</details>

### 후기
- 내 코드는 평균 1800ms 초가 걸리는데 다른 사람들 풀이는 50ms 내외이다.. 왜일까.