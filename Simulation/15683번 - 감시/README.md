### 15683번: 감시

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/15683)
2. **도움 블로그** : https://0m1n.tistory.com/115

**문제 조건**
- 스타트링크의 사무실은 1 X 1 크기의 정사각형으로 나누어져 있는 N X M 크기의 직사각형
- 사무실에는 총 K개의 CCTV가 설치되어있으며 5가지의 종류가 존재  
_1번 CCTV : 한 방향, 2번과 3번 CCTV : 2 방향, 4번 CCTV : 3방향, 5번 CCTV : 4방향_
- CCTV는 벽을 통과하여 감시할 수 없으며, **CCTV가 김사할 수 없는 영역을 사각지대**라고 함
- CCTV는 회전시킬 수 있으며, 회전은 항상 90도 방향으로 하며 감시하고자 하는 방향은 가로 또는 세로

**출력**  
- CCTV를 적절하게 방향을 설정하여 **사각 지대의 최소 크기**를 출력

### 풀이
1. _Backtracking_ 을 통해서 각각의 CCTV의 방향을 설정한 후에, 사각지대들을 확인하여 최솟값을 구함
2. 현재 `arr[][]`에 저장된 값을 `tmp[][]`을 선언하여 임시 저장
3. `cnt` 번째의 CCTV일 때의 방향을 결정 한 후, 해당 방향일 때의 CCTV의 감시지역을 -1로 저장
4. 이후에 다음인 `cnt + 1` 번째를 반복하여 모든 CCTV의 방향이 결정될 때까지 반복
5. _Backtracking_ 을 통해서 이 과정을 **각각의 CCTV의 방향을 모든 경우의 수를 확인**하여 사각지대를 파악
6. 만일, 다시 되돌아 올 때는 `arr[][]`에 저장된 값을 `tmp[][]`을 통해서 복구시킴
7. 위 과정들을 거쳐서 최종적인 모든 경우의 수에서 최소 사각지대의 크기를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void see(int x, int y, int d) {
    d %= 4;
    
    while(1) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        x = nx;
        y = ny;
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 6) break;
        if(map[nx][ny] != 0) continue;
        map[nx][ny] = -1;
    }
}
```
- CCTV의 방향이 설정되었을 떄의 감시영역을 설정하는 함수
- `d`가 4보다 클 수 있으므로 4의 나머지로 설정
- 방향인 `d`가 결정이 되었으면 다음 좌표인 `nx`, `ny`를 설정한 후에 맵 안이면서 벽이 아닐 때까지 반복
- 만일 다음 좌표가 CCTV인 경우는 건너뛰고 **빈 칸인 경우는 -1로 CCTV 감시지역으로 저장**

```cpp
void dfs(int cnt) {
    if(cnt == cctv.size()) {
        int zero = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 0) zero++;
            }
        }
        
        ans = min(ans, zero);
        
        return;
    }
    
    int tmp[9][9];
    int x = cctv[cnt].first;
    int y = cctv[cnt].second;
    
    for(int dir = 0; dir < 4; dir++) {
        copy_n(&map[0][0], 9 * 9, &tmp[0][0]);
        
        if(map[x][y] == 1) {
            see(x, y, dir);
        }
        else if(map[x][y] == 2) {
            see(x, y, dir);
            see(x, y, dir + 2);
        }
        else if(map[x][y] == 3) {
            see(x, y, dir);
            see(x, y, dir + 1);
        }
        else if(map[x][y] == 4) {
            see(x, y, dir);
            see(x, y, dir + 1);
            see(x, y, dir + 2);
        }
        else if(map[x][y] == 5) {
            see(x, y, dir);
            see(x, y, dir + 1);
            see(x, y, dir + 2);
            see(x, y, dir + 3);
        }
        
        dfs(cnt + 1);
        copy_n(&tmp[0][0], 9 * 9, &map[0][0]);
    }
}
```
- 백트래킹을 통해서 CCTV의 방향들을 모든 경우의 수를 살펴봄
- 모든 CCTV의 방향이 설정이 되었으면 해당 사각지대의 크기를 확인하여 `ans`값에 최솟값을 저장
- `tmp[][]`에 현재 `arr[][]`의 CCTV의 감시지역을 저장
- 해당 CCTV의 좌표에서 몇번 CCTV인지 확인하고, 방향이 설정되었으면 `see()`를 통해 `arr[][]`에 CCTV 감시지역을 추가
- 다음 `dfs()`를 호출하여 반복
- 백트래킹으로 다시 되돌아 오면은 이전 영역으로 돌아와야 하므로 `tmp[][]`에 저장된 값들을 `arr[][]`에 복사
</details>

### 후기
- CCTV를 회전해야 한다는 것에 PS 구상하는 것에 어려움을 느낌
- 임의의 방향이 결정된 후에는 코드상(?) 구현은 간단했음