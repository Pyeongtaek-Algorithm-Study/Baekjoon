### 1941번: 소문날 칠공주

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1941)


**문제 조건**
- 5 X 5 정사각형 자리 형태로 배치
- 자리 배치 중에서 **'소문날 칠공주'** 를 아래와 같이 결성하는 것을 목표  
    1. 7명의 여학생들로 구성(7명끼리는 반드시 가로나 세로로 인접)
    2. 7명 중에서 '이다솜파'의 여학생이 적어도 4명 이상 포함

**출력**  
- **'소문날 칠공주'** 를 결성할 수 있는 모든 경우의 수를 출력

### 풀이
1. 5 X 5 배열에서 `i`를 0부터 24까지 반복할 때 행은 i / 5, 열은 i % 5 이다.
2. `pos` 배열에 0을 18개, 1을 7개를 저장하여 순열 알고리즘을 통해 모든 순열 경우의 수를 구한다.
3. Board[][]와 vis[][]배열을 0으로 저장
4. **`seat[5][5]` 배열에 각 여학생들의 자리를 입력받고, `board[][]`는 해당 순열의 경우의 수의 좌표에 1로 저장한 후, `BFS`를 `vis[][]`에 돌면서 인접한 곳들은 1로 저장한다.**
5. `Board[][]`와 `vis[][]`배열을 비교하여 Board의 1의 좌표가 vis에선 0일 경우, 7명의 자리가 완전히 서로 인접한 것이 아니므로 `false`를 반환
6. 서로 인접하여 `true`로 반환한 경우, 해당 좌표들 중 '이다솜파' 여학생의 인원이 4명이상이면 만족하므로, `ans` 를 중가
7. `pos` 배열의 순환을 돌면서 좌표의 모든 케이스를 확인하고, 최종 확인 된 경우의 수를 출력

### 핵심 코드

```
int pos[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                1, 1, 1, 1, 1, 1, 1};
bool bfs(vector<pair<int, int>> v) { 
    fill(&vis[0][0], &vis[4][5], 0);
    fill(&board[0][0], &board[4][5], 0);
    
    for(auto c : v) board[c.x][c.y] = 1;
   
    queue<pair<int, int>> q;
    q.push({v[0].x, v[0].y});
    vis[v[0].x][v[0].y] = 1;
    
    while(!q.empty()){       
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){            
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }    
        
    }     
    for(auto c : v)   
        if(vis[c.x][c.y] == 0) return false;
    return true;

}

```
- `pos` 배열에 25개 중에 뒤에서 부터 1을 7개 채우고, 나머지를 0으로 채운다.
- `pos`를 통해 5 X 5 배열의 좌표를 얻은 후, 해당 좌표를 `Board[][]`에 저장한다.
- BFS를 돌면서 `visited[][]` 에 방문한 곳을 1로 채운다.
- **`Board[][]` 와 `visited[][]`를 비교하여 방문한 곳이 서로 같다면 7명이 인접한 것이므로 `true`, 다르다면 `false` 반환한다.**
```
do {        
    vector<pair<int, int>> v;

    for(int i = 0; i < 25; i++) {            
        if(pos[i] == 1) v.push_back({(i / 5), (i % 5)});
    }         
    bool conn = bfs(v);
    
    if(conn) {            
        int cnt = 0;
        for(auto c : v) if(seat[c.x][c.y] == 'S') cnt++;
        if(cnt >= 4) ans++;
    }    
} while(next_permutation(pos, pos+25));
```
- `pos[]` 에 1인 위치를 좌표로 변환한다. 행(i/5), 열(i%5)
- `connection` 으로 7명의 위치가 서로 인접한지 확인하고 true일 경우 다음단계 진행한다.
- 7명 중에서 '이다솜파' 가 4명 이상이면 경우의 수 `ans++` 한다.
- **반복문을 통해 pos[]의 순열이 종료할 때까지 반복한다.**
