### 0000번: 0000

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1707)
2. **도움 블로그** : https://velog.io/@matcha_/%EB%B0%B1%EC%A4%80-1707-%EC%9D%B4%EB%B6%84%EA%B7%B8%EB%9E%98%ED%94%84-C-BFS-DFS

**문제 조건**
- 그래프의 정점의 집합을 둘로 분할
- 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있는 그래프를 **이분 그래프(Bipartite Graph)** 라고 함.

**출력**  
- 각각의 그래프가 **이분 그래프**이면 "YES", 아니면 "NO"를 순서대로 출력

### 풀이
1. 초기의 각각의 정점의 색깔을 없는 것부터 시작
2. 1번 노드부터 마지막 노드까지 방문하지 않은 노드일 경우 해당 노드부터 _BFS_ 를 시작
3. 시작노드의 색깔은 임의의 색(빨간색)으로 시작해서 해당 노드에 인접한 것은 반대색깔(파란색)으로 탐색을 계속 진행
4. 계속하여 탐색하다가 현재노드에서의 색상이 다음 인접한 노드의 색상을 확인할 때 **자기 색상과 같은 경우**가 있으면, 이미 이분 그래프가 불가능함으로 탐색을 종료
5. 만일 그러한 경우 없이 계속 전부 진행한 경우는 이분 그래프가 맞음
6. 위 과정들에서 이분 그래프인지 아닌지를 얻었음으로 해당 결과를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
bool bfs(int st) {
    queue<int> Q;
    Q.push(st);
    color[st] = RED;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int nxt_color = (color[cur] == RED ? BLUE : RED);
        
        for(int i = 0; i < edges[cur].size(); i++) {
            int nxt = edges[cur][i];
            if(!color[nxt]) {
                color[nxt] = nxt_color;
                Q.push(nxt);
            } else if(color[cur] == color[nxt]) {
                return false;
            }
        }
    }
    
    return true;
}
```
- `queue`에 시작 노드인 `st`를 넣고 색상을 `RED`로 저장
- `queue`에서 꺼낸 노드의 색상 `nxt_color`가 `RED`이면 다음 색상은 `BLUE`, 아니면은 `RED`로 저장
- 인접한 노드를 계속 탐색하고, 다음 노드 색상이 없으면은 `nxt_color`를 저장
- 인접한 노드의 색상이 현재 색상과 같은 경우, 이미 이분 그래프로 만들 수 없는 것임으로 `false`로 함수 반환
- 전부 다 탐색을 한 것이면은 이상이 없는 것임으로 `true`로 반환

```cpp
void solve() {
    bool ans = true;
    for(int i = 1; i <= v; i++) {
        if(!color[i]) ans = bfs(i);
        // 만일, 이분그래프가 아닐 경우, 바로 종료
        if(!ans) break;
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
}
```
- 1번 노드부터 마지막 노드에서 만일 색상이 없는 경우 해당 숫자부터 `bfs()`를 통해 색상들을 저장
- 탐색이 끝난 후, `ans`에 저장된 값을 확인하여 만일 `false`가 하나라도 있으면, 이분 그래프가 불가능 함으로, 반복문 종료
- 해당 `ans`에 따라서 YES, NO를 출력
</details>

### 후기
- 색상으로 구분하는 것이 독특한 PS였음
- 새롭게 인사이트를 얻을 수 있는 재밌는 알고리즘의 느낌을 받음