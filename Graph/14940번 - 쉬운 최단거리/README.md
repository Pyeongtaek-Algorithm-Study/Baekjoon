### 14940번: 쉬운 최단거리

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/14940)

**문제 조건**
- 지도의 크기는 세로 `n`, 가로 `m`
- 0은 갈 수 없는 땅, 1은 갈 수 있는 땅, 2는 목표지점(only 1개)

**출력**  
- 각 지점에서 목표지점까지의 거리를 출력

**원래 갈 수 없는 땅의 위치는 0, 갈 수 있는 땅 중에서 도달할 수 없는 위치는 -1 출력** 

### 풀이
1. 문제에서 요구했던 각 지점에서 출발해서 목표지점까지의 거리는 반대로 생각하면 **목표지점에서 출발 해 갈 수 있는 땅까지의 거리인 것과 같은 것**
2. 최단거리를 각 위치에 입력하므로 `BFS`를 활용하여 풀이
3. 지도의 위치를 `arr[][]`에 저장하고, 목표지점부터 각 위치의 거리를 `dist[][]`에 저장
4. `dist[][]`은 처음에 -1로 초기화하고, 입력 값이 0인 경우 `dist[][]` 위치에도 0으로 저장
5. 2인 좌표를 찾으면 `Q`에 넣고 `BFS`를 실행하여 각 위치거리를 구해서 `dist[][]`에 저장
6. 더이상 찾을 거리가 없을 경우 최종 `dist[][]` 을 출력

<details><summary> 핵심 코드 </summary>

```
cin >> n >> m;
memset(dist, -1, sizeof(dist));

for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> arr[i][j];
        if(!arr[i][j]) dist[i][j] = 0;
    }
}

```
- `memset(dist, -1, sizeof(dist))` 로 `dist[][]`을 전부 -1로 초기화 _#include <string.h> 필요_
- `arr[][]`에 값을 입력 받고, 만약 값이 0인 경우 `dist[][]` 좌표에도 0을 저장
```
void BFS() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; 
            Q.push({nx,ny});
        }
    }
}
```
- 두번째 `if` 문을 통해서 갈 수 없는 위치인 0과 이미 방문한 위치를 제외한 곳 _(-1이 아닌 곳)_ 을 탐색
- `dist[nx][ny]`의 값에는 현재 위치 값 + 1 을 저장
- 반복적으로 탐색하기 위에 `Q`에 넣기
</details>
