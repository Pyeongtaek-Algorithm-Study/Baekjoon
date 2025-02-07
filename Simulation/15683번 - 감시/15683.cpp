#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[9][9];
vector<pair<int, int> > cctv;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int ans = 1e9;

void input() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6) cctv.push_back({i, j});
        }
    }
}

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

void solve() {
    dfs(0);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;    
}