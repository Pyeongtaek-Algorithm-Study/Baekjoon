### 2636번: 치즈

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/2636)
2. **도움 블로그** : 

**문제 조건**
- 정사각형 칸들로 이루어진 사각형 모양의 판, 그 위에 얇은 치즈가 놓여짐
- 치즈는 가운데에 하나 이상의 구멍이 존재
- 치즈는 공기 중에 놓으면 공기와 접촉된 칸은 한 시간 뒤에 녹음, **단, 치즈 구멍에 있는 부분은 녹지 않음**

**출력**  
- 치즈가 모두 녹아 없어지는데 걸리는 시간과 전부 녹기 한 시간 전에 남아있던 치즈조각이 놓여 있는 칸의 수를 출력

### 풀이
1. 치즈가 공기중에 접촉된 칸을 확인 하기 위해 `bfs()`로 순회
2. 사각형 판에 가장자리는 치즈가 놓여있지 않으므로 (0, 0)부터 `bfs()` 시작
3. 공기가 위치한 칸을 0에서 2로 변경
4. `nx`, `ny` 위치에서 공기와 접촉 중인 치즈를 발견하면 2로 변경
5. `result` 변수에는 `bfs`를 돌기 전에 치즈조각이 놓여있는 칸의 개수를 저장
6. `while`문으로 무한반복하며, 남아있는 치즈조각이 없으면은 `finish`의 값이 0이므로 종료되게 설정
7. 치즈조각이 남아있으면 `day` 값을 1 증가시키고, `result` 값에는 기존 남아있던 치즈조각 수를 기억
8. 사각형 판에 치즈조각이 전부 사라질 때 까지 반복한 후, `day`와 `result`를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void bfs() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        cheese[cur.X][cur.Y] = 2;
        vis[cur.X][cur.Y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 미리 범위를 체크
            if(cheese[nx][ny] == 1) cheese[nx][ny] = 2;
            if(cheese[nx][ny] == 2 || cheese[nx][ny] == 1 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

```
- 기본적인 `BFS` 구조와 같음
- `nx`, `ny`에서 치즈조각이 발견될 경우 공기와 접촉중인 치즈조각이므로 2로 변경

```cpp
void solve() {
    int result = 0;
    while(true) {
        int finish = 0;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(cheese[i][j] == 1) {
                    leaving++;
                    finish = 1; 
                }
            }
        }
        Q.push({0, 0});
        bfs();
        if(!finish) break;
        result = leaving;
        day++;
        init();
    }
    cout << day << '\n' << result;
}
```
- `result` 값은 녹기 전 치즈조각을 기억하는 변수
- 이중 `for`문으로 치즈조각이 놓여있는 칸의 수를 `leaving`에 저장
- 치즈조각이 남아있을 경우 `finish`를 1로 저장
- `finish`가 0이면은 남은 치즈조각이 없는 것이므로 `while`문을 종료되게 설정
- `result` 값에 leaving 값을 저장
- `day`에 1을 추가로 저장
- 기존 `vis`와 `leaving` 값등을 전부 초기화
- 치즈조각이 전부 사라질 때 까지 반복
- 마지막으로, `day`와 `result`값을 출력
</details>

### 후기
- 녹기 전 한시간 치즈조각의 칸 수를 구하는 것이 힘들었다. 이에, `bfs()`를 돌기 전에 치즈조각을 구해서 `leaving`에 저장