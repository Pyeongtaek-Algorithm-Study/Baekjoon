### 15591번: MooTube

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/15591)
2. **도움 블로그** : 

**문제 조건**
- 농부 존은 남는 시간에 MooTube라 불리는 동영상 공유 서비스 만듦.
- 소들은 MooTube에 1부터 N까지 번호가 붙여진 N개의 동영상들을 서로 공유할 수 있음
- 농부 존은 모든 MooTube 동영상에 대해 "연관 동영상" 리스트를 만들기로 해서, 소들은 지금 보고 있는 동영상과 연관성이 높은 동영상을 추천
- 두 동영상이 서로 얼마나 연관이 있는지 측정하는 단위 **"USADO"**
- N개의 동영상은 각 동영상끼리 가는 경로가 반드시 1개 이상 존재
- 존은 임의의 두 쌍 사이의 동영상의 USADO를 그 경로의 모든 연결들의 USADO 중 최솟값으로 결정
- 각 테스트 케이스에서 USADO가 K 이상인 **추천 동영상의 개수**를 찾기

**출력**  
- 농부 존의 각 질문에 대한 답변을 출략

### 풀이
1. _DFS, BFS_ 로 풀 수 있으며, _BFS_ 방식으로 설명 진행
2. 각 질문인 시작 동영상 V와 USADO의 K로 시작 동영상에서 각 경로들을 탐색
3. 경로에서 USADO가 **K이상**일 경우 탐색 진행
4. **방문하지 않은 동영상**을 찾을 때마다 개수 증가
5. 모든 경로를 확인 후, 찾은 영상 개수를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
int bfs(int k, int v) {
    int vis[5001] = { 0, };
    queue<int> Q;
    Q.push(v);
    
    int cnt = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        vis[cur] = 1;
        
        for(int i = 0; i < edges[cur].size(); i++) {
            int nxt = edges[cur][i].X;
            int usado = edges[cur][i].Y;
            
            if(vis[nxt] || usado < k) continue;
            
            cnt++;
            vis[nxt] = 1;
            Q.push(nxt);
        }
    }
    
    return cnt;
}
```
- `bfs()`로 각 경로에서 방문하지 않은 동영상과 `k`값 이상인지 확인
- 탐색을 진행하면서 찾는 동영상마다 `vis[]`로 방문처리 후, 영상 개수 1이상 증가
- 탐색할 수 있는 경로까지 진행 후 최종적으로 구한 `cnt` 반환
</details>

### 후기
- 다른 풀이로, _Union-Find_ 로 하는 방식도 있는데 따로 풀이를 하진 않음.