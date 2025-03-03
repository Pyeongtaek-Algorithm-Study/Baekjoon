#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;
int island[11][11];
bool vis[11][11];
vector<pair<int, int> > v;
vector<vector<int> > bridge;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int parents[101];

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> island[i][j];
            if(island[i][j]) v.push_back({i, j});
        }
    }
    for(int i = 1; i <= 100; i++) {
        parents[i] = i;
    }
}

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

void bfs(int x, int y, int num) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        island[cur.X][cur.Y] = num;
        vis[cur.X][cur.Y] = true;
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || island[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int Find(int x) {
    if(x == parents[x]) return x;
    return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parents[b] = a;
}

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}