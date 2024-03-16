### 2210번: 숫자판 점프

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/2210)

**문제 조건**
- 5 X 5 크기의 숫자판에 각각의 칸에는 숫자를 입력
- 임의의 위치에서 시작해서, 인접해 있는 상하좌우 4 방향으로 다섯 번 이동하여, **각 칸에 적혀 있는 숫자를 차례로 붙여 6자리의 수를 생성**
- **이동할 때에는 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000111과 같은 수도 가능**

**출력**  
- 5 X 5 숫자판을 입력했을 때, **만들 수 있는 모든 여섯 자리들의 경우의 수**를 출력

### 풀이
1. 임의의 위치에서 시작하여 `DFS` 를 돌면서, 6자리가 될 때 까지 재귀적으로 반복한다.
2. 방문했던 곳을 다시 방문할 수 있으므로, vis[][] 배열은 따로 생성하지 않는다.  
즉, 해당 위치에서 `DFS`로 4방향 모두 또 방문할 수 있도록 한다.
3. 6자리가 생성될 경우, 해당 값을 `vector`에 저장한다.
4. 가능한 모든 6자리를 저장한 후, 중복된 6자리는 제거한다. 
5. 해당 `vector.size()`를 통해 경우의 수를 출력한다.

### 핵심 코드

```
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        dfs({i, j}, 0, 0);
    }
}

void dfs(pair<int, int> cur, int cnt, int value) {
    if(cnt == 6) {
        ss.push_back(value);
        return;
    }
    else {
        for(int j = 0; j < 4; j++) {
            int nx = cur.X + dx[j];
            int ny = cur.Y + dy[j];
            if(nx < 0 || nx >=5 || ny < 0 || ny >= 5) continue;
            dfs({nx, ny}, cnt+1, value * 10 + board[cur.X][cur.Y]);
        }
    }
}
```
- 5 X 5 숫자판에서 시작 위치를 각각 모든 위치에서 시작하여 6자리가 생성될 때까지 `DFS` 진행
- 이전에 방문했던 것과 상관없이 숫자판 밖으로 나가지 않는 경우를 제외하고 재귀적으로 `DFS` 진행
- 6자리를 생성할 때까지 반복하여 `vector ss` 에 저장
```
sort(ss.begin(), ss.end());
ss.erase(unique(ss.begin(), ss.end()), ss.end());
```
- 모든 6자리의 수가 저장된 ss에 정렬을 진행
- 중복된 수를 제거하기 위해 `v.erase(unique(v.begin(), v.end()), v.end())` 작성 _( v 는 vector를 의미 )_

