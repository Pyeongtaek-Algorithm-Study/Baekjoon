### 11724번: 연결 요소의 개수

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/11724)

**문제 조건**
- 무방향 그래프가 주어졌을 때, 연결 요소의 개수 구하기

**출력**  
- 그래프들의 연결 요소들의 개수 출력

### 풀이
1. 간선의 개수 만큼 `vector`에 입력을 받는다.
2. 무방향이므로 u -> v 와 v -> u 방향도 함께 입력한다.
3. 방문하지 않은 정점에 대해 dfs를 돌면서 `cnt++` 하기
4. 이를 반복하며 모든 정점을 확인하기

### 핵심 코드

```
for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u); // 무방향 그래프이기 때문에 양쪽으로 입력
}

```
- 양 끝점 u -> v 와 v -> u로 `vector`에 추가

```
void dfs(int x) {
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++) {
        int cur = graph[x][i];
        if(!visited[cur]) dfs(cur);
    }
}
```
- dfs로 해당 정점을 방문 표시 (`true`) 하고, 해당 정점 `vector` 에 방문 가능 간선이 있으면 `dfs`로 돌면서 정점 확인
