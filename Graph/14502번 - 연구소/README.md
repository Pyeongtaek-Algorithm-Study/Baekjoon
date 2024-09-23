### 14502번: 연구소

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14502)
2. **도움 블로그** : 

**문제 조건**
- 연구소에 바이러스가 유출되어, 연구소에 3개의 벽을 세워서 바이러스의 확산을 막고자 함.
- 연구소의 크기는 `N` X `M`인 직사각형이며, 연구소에는 벽, 빈 칸, 바이러스가 존재
- 바이러스는 상하좌우로 인접한 곳에 모두 퍼져나가며 연구소에서 세울 수 있는 벽은 3개이며, **반드시 3개를 다 사용**
- 바이러스가 확산이 종료되고, 바이러스가 퍼질 수 없는 공간을 안전 영역이라 함.

**출력**  
- 연구소를 입력받았을 때, 임의의 공간에 3개의 벽을 세워 안전 영역의 최대 크기를 출력

### 풀이
1. 바이러스가 퍼지는 것을 _DFS_ 로 구현하여 퍼지도록 했다.
2. 벽을 세울 수 있는 공간은 0이기 때문에 3중 반복문을 통해 0인 위치들을 `i`, `j`, `k`에 저장
3. 처음 `after_lab`은 `lab`의 값을 복사한 후, 3개의 벽을 세워진 곳에 추가로 저장
4. 그 뒤, `spread_virus()`를 실행하여 `dfs`를 통해 바이러스를 확산시킨다.
5. `find_safe()`함수를 실행하여 안전 영역인 0인 공간을 찾아 기존 안전 영역 개수보다 크면은 갱신한다.
6. 다르게 벽을 세울 수 있는 상황을 반복하기 위해 `vis[][]`과 `safe_zone`을 0으로 초기화
7. 연구소에서 3개의 벽을 세울 수 있는 모든 상황을 반복하며 최대로 되는 안전 영역 찾기

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void make_wall(int one, int two, int thr) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            after_lab[i][j] = lab[i][j];
        }
    }
    after_lab[one/m][one%m] = 1;
    after_lab[two/m][two%m] = 1;
    after_lab[thr/m][thr%m] = 1;
}

void dfs(int r, int c) {
    vis[r][c] = true;
    after_lab[r][c] = 2;
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && after_lab[nr][nc] != 1) {
            dfs(nr, nc);
        }
    }
}

void spread_virus() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(after_lab[i][j] == 2 && !vis[i][j]) {
                dfs(i, j);
            }
        }
    }
}

void find_safe() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!after_lab[i][j]) {
                safe_zone++;
            }
        }
    }
    ans = max(ans, safe_zone);
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }
    safe_zone = 0;
}

void solve() {
    for(int i = 0; i < n * m; i++) {
        if(lab[i/m][i%m]) continue;
        for(int j = i + 1; j < n * m; j++) {
            if(lab[j/m][j%m]) continue;
            for(int k = j + 1; k < n * m; k++) {
                if(lab[k/m][k%m]) continue;
                make_wall(i, j, k);
                spread_virus();
                find_safe();
                init();
            }
        }
    }
    cout << ans << "\n";
}
```
- `solve()`함수에서 `i`, `j`, `k`로 벽을 세울 수 있는 0인 공간인 값을 찾아 `make_wall()`를 실행하여 `after_lab[][]`에 벽이 세워진 연구소 상태를 저장
- 연구소를 돌면서 바이러스가 있는 위치에서 시작하여 바이러스를 퍼트린다.
- 바이러스를 다 퍼트리고 난 후 안전 영역을 찾기 위해 `find_safe()`를 실행하여 0인 공간의 개수를 찾는다.
- `ans`값에 해당 연구소 상태에서 안전 영역의 개수를 비교하여 더 큰 값이면 갱신하도록 한다.
- 다르게 벽을 세울 수 있는 상황을 찾아서 탐색하기 위해 `init()`를 실행하여 `vis[][]`과 `safe_zone`값을 초기화한다.
- 모든 상황을 다 조사한 후, `ans` 값을 출력
</details>

### 후기
> 이 풀이는 제가 푼 코드의 해석이지만, GPT에게 부탁하여 리팩토링한 14502_GPT.cpp 파일은 스스로 해석하길 바람.
- 0인 구역만을 `spaces` 공간을 찾아서 `vector` 넣어서 활용하는 것은 생각지 못했다. 이러면은 불필요한 반복문을 더 줄일 수 있었다.
- 방문한 곳 제외와 벽이 있는 곳을 제외하는 조건 자체가 0인 구역을 가라는 의미와 같다라는 것을 생각지 못했다.(41번줄)