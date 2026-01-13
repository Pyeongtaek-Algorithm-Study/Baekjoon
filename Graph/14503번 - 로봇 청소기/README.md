### 14503번: 로봇 청소기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14503)
2. **도움 블로그** :https://yeons4every.tistory.com/161#google_vignette 

### 풀이
1. 방향은 시계방향이지만, 로봇 청소기가 청소할 때 회전하는 방향은 반시계 방향
2. 로봇 청소기의 처음 위치는 항상 비워져있음으로 청소 개수인 `cnt`는 항상 1부터 시작
3. 주변 4방향에서 청소할 수 있는 칸이 있다면 해당 칸으로 이동한 후 재귀 탐색
4. 청소할 수 있는 칸이 없다면 후진 칸에 이동할 수 있다면 이동(단, 방향은 그대로 유지한 채로 탐색)
5. 위 과정을 계속하여 반복

### 핵심 코드

<details>
<summary>코드 보기</summary>

```java
private static void dfs(int x, int y, int dir) {
    room[x][y] = -1;
    
    for (int i = 0; i < 4; i++) {
        // 반시계 방향임으로 +3
        dir = (dir + 3) % 4;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0) {
            cnt++;
            dfs(nx, ny, dir);
            return;
        }
    }
    
    int backDir = (dir + 2) % 4;
    int bx = x + dx[backDir];
    int by = y + dy[backDir];
    if (bx >= 0 && bx < n && by >= 0 && by < m && room[bx][by] != 1) {
        dfs(bx, by, dir);
    } 
}
```
</details>

### 후기
- 반시계 방향으로 회전한다는 것으로 `dir` 값에 3을 더해야 했음
- `return`을 통해서 탐색하는 함수들을 종료해야 다음 코드로 넘어가지 않아 정확한 청소 개수를 구할수 있음.