### 6593번: 상범 빌딩

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/6593)

**문제 조건**
- 상범 빌딩은 각 변의 길이가 1인 정육면체가 여러개로 이뤄짐.
- 각 칸에서 인접한 6개의 칸 (동, 서, 남, 북, 상, 하)로 1분을 들여 이동할 수 있음.
- 상범 빌딩에서는 오직 출구를 통해서만 탈출할 수 있음.

**출력**  
- 'S'에서 시작하여 출구인 'E'까지 걸리는 시간과 함께 'Escaped in x minute(s).' 출력, 만일 탈출하지 못하면은 'Trapped!'를 출력

### 풀이
1. 기존 그래프문제처럼 `BFS`를 통해 해결
2. 기존 동서남북으로만 가는 부분에서 z축을 추가하여 상하를 갈 수 있도록 설정
3. 각 칸을 입력받을 때 '`S`'와 '`E`'의 위치를 저장
4. `queue<vector<int>> Q`로 앞으로 갈 칸의 x,y,z 축의 위치를 `vector`에 저장하여 `Q`에 `push`
5. 앞으로 이동 가능한 칸을 `Q`에 넣으면서, 걸리는 시간을 체크하기 위해 기존칸 값 + 1을 다음 칸에 저장
6. '`E`'를 도착할 때 까지 반복

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
int dx[6] = {0, -1, 0, 1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

queue<vector<int>> Q;

void solve() {
    while(!Q.empty()) {
        int z = Q.front()[0];
        int y = Q.front()[1];
        int x = Q.front()[2];
        Q.pop();
        
        if(building[z][y][x] == 'E') break;
        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l) continue;
            if(building[nz][ny][nx] == '#' || vis[nz][ny][nx]) continue; 
            vector<int> n_tmp = {nz, ny, nx};
            Q.push(n_tmp);
            vis[nz][ny][nx] = vis[z][y][x] + 1;
        }
    }
}
```
- `dx`, `dy`, `dz`를 설정하여 동, 서, 남, 북, 상, 하를 갈 수 있도록 설정
- `queue`에 3개의 축의 위치를 저장할 수 있도록 `vector`를 입력받음.
- `BFS`를 통해 다음으로 이동할 수 있는 `nx`, `ny`, `nz`를 파악
- `vis[][][]` 배열을 통해 갈 수 있는 각 칸에 걸리는 시간을 +1 씩하여 `E`까지 도달할 떄 까지 반복
</details>

### 후기
- 16%까진 'trapped!' 에 대한 것이고 그 이후에는 '최소 시간 파악' 인 것 같음.
- 인자가 3개여서 `pair` 구현이 힘들어 `vector`를 인자값에 저장했는데 괜찮은 것같음.