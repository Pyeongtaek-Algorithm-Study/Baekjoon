### 17472번: 다리 만들기 2

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/17472)
2. **도움 블로그** : 

**문제 조건**
- 섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 함.
- 이 나라의 지도는 N x M 크기의 이차원 격자로 나타낼 수 있고, 격자의 각 칸은 땅 또는 바다
- 섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 말하고, 색칠되어 있는 칸이 땅이며 다리를 건설하고자 함
- **다리의 규칙**
    - 다리는 바다에만 건설할 수 있으며, 다리의 길이는 격자에서 다리가 차지하는 칸의 수로 섬과 섬를 연결
    - 다리의 양 끝에는 섬과 섬이 있어야 하며, 다리 중간에 방향이 바뀌면 안되며 길이는 2 이상이여야 함
    - 임의의 섬 A와 B를 연결하는 다리 중간에 섬 C와 인접하게 지나는 경우, 다리가 섬 C를 연결하는 것이 아님


**출력**  
- 모든 섬을 연결하는 **다리 길이의 최솟값**을 출력
- 모든 섬을 연결하는 것이 불가능하면 -1을 출력

### 풀이
1. 나라의 지도가 주어졌을 때, 섬의 땅 부분을 1로, 바다를 0으로 입력 받으므로 각 섬의 번호를 부여
2. 각각의 땅에서 상하좌우 방향으로 바다로 나아갈 때 거리가 2 이상이며 다른 번호의 섬이 나오는 경우를 각각 저장
3. 위 과정을 통해 해당 지도에서 임의의 A와 B 섬을 연결할 수 있는 다리의 경우를 다 구한 후, 거리를 기준으로 **오름차순**으로 정렬
4. _Kruskal_ 알고리즘을 활용하여 가장 적은 비용으로 연결 할 수 있는 다리들로 연결
5. 연결한 다리 개수가 섬의 개수 - 1 만큼인지 확인하여 **최소 다리 길이**를 출력
6. 다리 개수가 부족할 경우 모든 나라를 연결할 수 **없는 것**이므로, -1을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void connect(int x, int y) {
    int cur_island_num = island[x][y];
    
    for(int d = 0; d < 4; d++) {
        int o_x = x, o_y = y;
        int cnt = 0;
        int next_island = 0;
        while(1) {
            int nx = o_x + dx[d];
            int ny = o_y + dy[d];
            o_x = nx, o_y = ny;
            next_island = island[nx][ny];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || next_island == cur_island_num) break;
            if(next_island != 0) {
                if(cnt >= 2) {
                    bridge.push_back({cnt, island[x][y], island[nx][ny]});
                }
                break;
            }
            cnt += 1;
        }
    }
}
```
- `connect()`는 현재 섬의 땅 위치인 (`x`, `y`)에서 다른 섬을 연결할 수 있는 다리를 찾는 함수
- `cur_island_num` 은 현재 땅의 섬 번호를 저장
- 다음 위치를 위한 임의의 변수 `o_x`, `o_y`, 다리의 길이인 `cnt`, 다음 위치의 섬 번호인 `next_island` 
- 다리를 연결하기 위한 조건으로 `next_island` 가 현재 섬과 다르고, 바다가 아니고 `cnt`가 2이상일 때 연결 가능한 다리임으로 `bridge`에 추가
- 위 과정들을 `nx`, `ny`로 상하좌우 일직선 방향으로 모두 확인

```cpp
void solve() {
    int island_num = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(island[i][j] && !vis[i][j]) {
                bfs(i, j, island_num);
                island_num++;
            }
        }
    }
    
    for(auto &it : v) {
        connect(it.X, it.Y);
    }
    
    sort(bridge.begin(), bridge.end());
    
    int edge_cnt = 0;
    int min_weight = 0;
    bool chk = false;
    for(int i = 0; i < bridge.size(); i++) {
        vector<int> edge = bridge[i];

        if(Find(edge[1]) == Find(edge[2])) continue;
        Union(edge[1], edge[2]);
        min_weight += edge[0];

        if(++edge_cnt == island_num - 2) {
            chk = true;
            break;
        }
    }
    
    cout << (chk ? min_weight : -1) << '\n';
}
```
- `bfs()`를 통해 지도의 격자에서 땅 부분일 때 해당 섬의 번호를 부여
- `connect()` 를 통해 `bridge` 배열에 섬과 섬을 연결할 수 있는 모든 다리의 경우의 수를 저장
- `bridge` 배열에서 다리의 길이를 기준으로 오름차순으로 정렬
- 다리의 개수인 `edge_cnt`, 다리들의 총 길이 합인 `min_weight`, 모든 섬 연결 확인을 위한 `chk`
- _Kruskal_ 알고리즘 로직으로 구체적인 설명은 제외
- `chk`를 통해 모든 섬을 연결했으면 `min_weight`를 출력하고, 아닌 경우 -1을 출력

</details>

### 후기
- PS를 떠올리는 것은 어렵지 않았지만, 답을 도출하는 과정이 여러 단계여서 코드가 길었음