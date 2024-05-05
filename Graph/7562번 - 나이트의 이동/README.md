### 7562번: 나이트의 이동

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/7562)

**문제 조건**
- 체스판 위에 한 나이트가 존재
- 입력의 첫째 줄에는 테스트 케이스를 주어줌.  
_(※ 테스트 케이스만큼 정답을 출력)_
- 차례대로, 체스판의 한 변의 길이, 처음 나이트의 위치와 나이트가 목표로하는 칸을 주어줌.

**출력**  
- 체스말인 나이트가 체스판에서 **최소 몇 번만에 목표지점**을 갈 수 있는지 출력

### 풀이
1. 체스말인 나이트의 처음 위치를 `Q`에 넣기
2. `Q`의 가장 첫번째를 출력한 후에 다음으로 이동할 수 있는 칸을 `dx`, `dy`를 통해 `nx`, `ny`를 구하기
3. `nx`, `ny`로 체스판에서 갈 수 있는 위치를 확인하며, 기존에 갔던 곳인지 체크
4. 다음으로 갈 수 있는 곳이 있으면 **기존 위치 값에 +1 한 값을 다음칸에 입력**하고 방문을 체크
5. 이를 반복하며 목표지점까지 도달하는지 체크하여 해당 위치까지 몇 번인지를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    Q.push({kx, ky});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X][cur.Y] = true;   
        if(cur.X == gx && cur.Y == gy) {
            break;
        }
        for(int i = 0; i < 8; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if( vis[nx][ny] ) continue;
            vis[nx][ny] = true;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << board[gx][gy] << "\n";
}

void reset() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            board[i][j] = 0;
            vis[i][j] = false;
        }
    }
    while(!Q.empty()) Q.pop();
}
```
- `Q`의 처음에는 나이트의 초기 위치인 `{kx, ky}`를 넣는다.
- 이를 꺼내서 다음 칸으로 이동할 수 있는 칸들을 구해서 가능한 곳이 있으면 `Q`에 넣는다.
- 다음 칸으로 이동하는 것은 기존 위치에서 +1 한 것이다.
- 해당 위치가 입력 받은 목표지점인지 확인하여 반복문을 종료한다.
- 반복문이 종료되면 **목표지점에 저장된 수**를 출력
- 해당 케이스가 종료되면 `Q`에 남아있는 값들과 `board`와 `vis`를 모두 초기 상태로 초기화 진행한다.

</details>