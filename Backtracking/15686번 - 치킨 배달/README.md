### 15686번: 치킨 배달

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/15686)
2. **도움 블로그** : 

**문제 조건**
- 문제 조건과 관련한 것 서술

**출력**  
- 문제가 요구하는 정답 출력 서술

### 풀이
1. _Backtracking_ 을 통해서 입력받은 치킨 가게들에서 m개를 만들 수 있는 경우의 수들을 확인
2. 각각의 m개일 때의 경우의 수에서 _BFS_ 를 통해 `vis[][]`에 치킨 거리들을 저장
3. 각각의 집 위치에서의 치킨 거리들을 더하여 더 작게 나올 수 있는 합산 치킨 거리가 있을 시 값을 갱신
4. 모든 경우의 수들을 통해 **합산 치킨 거리 최솟값**을 구했을 경우 해당 최솟값을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void backtracking(int cnt, int cur) {
    if(cnt == m) {
        fill_n(&vis[0][0], 51 * 51, 0);
        queue<pair<int, int> > Q;
        
        for(int i = 0; i < chicken.size(); i++) {
            if(chi_vis[i]) {
                Q.push({chicken[i].first, chicken[i].second});
                
                // vis[][]에서 다시 출발 지점으로 방문하는 것을 막기 위함
                vis[chicken[i].first][chicken[i].second] = 1;
            }
        }
        
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = vis[x][y] + 1;
                Q.push({nx, ny});
            }
        }
        
        // 치킨으로부터 집까지 거리들의 합
        int distance = 0;
        for(int i = 0; i < home.size(); i++) {
            // 치킨 집 시작이 1로 시작함으로 1을 뺌
            distance += (vis[home[i].first][home[i].second] - 1);
        }

        ans = min(ans, distance);

        return;
    }
    
    for(int nxt = cur; nxt < chicken.size(); nxt++) {
        chi_vis[nxt] = true;
        backtracking(cnt + 1, nxt + 1);
        chi_vis[nxt] = false;
    }
}
```
- `backtracking()` 매개변수로 현재 치킨 가게 수 `cnt`, 현재 오픈한 치킨 가게의 순서인 `cur`
- `chi_vis[]`는 오픈한 치킨 가게를 나타내서 `cur`을 시작하여 `nxt`에 저장
- 해당 `nxt`번째의 치킨 가게를 오픈후 다음 오픈할 치킨 가게를 `backtracking()`을 호출하여 탐색
- 탐색을 진행 하다가 `cnt`가 `m`개 일 때 해당 오픈된 치킨 가게들로 각 칸의 거리를 저장할 `vis[][]` 선언
- 각 오픈한 치킨 가게들 위치는 치킨 거리를 1로 저장 (_방문하는 것을 방지 목적_)
- _BFS_ 를 통해 `vis[][]`에 각 칸에 치킨 거리의 최소 거리들로 저장
- 각 집에서 치킨 거리의 합을 더하는 데 아까 최초 시작 치킨 거리를 1로 저장했으므로 **-1을 한 후 합산**
- `ans` 값과 합산한 `distance` 값과 비교하여 더 최솟값으로 갱신
- 위 과정들을 _Backtracking_ 탐색을 통해 여러 개의 치킨 가게들에서 `m`개를 하는 경우의 수들을 모두 비교하여 `ans` 값에는 **모든 경우의 수에서 최소 치킨 거리가 저장**
</details>

### 후기
- 30% 정도에서 틀림