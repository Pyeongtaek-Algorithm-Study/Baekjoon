#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX 10001

int r, c;
char forest[51][51];
bool vis[51][51];
int dist[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Q;
vector<pair<int, int>> flow;
pair<int, int> d_c, s_c;

void input() {
    cin >> r >> c;
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> forest[i][j];
            dist[i][j] = MAX;
            
            if(forest[i][j] == '*') {
                flow.push_back({i, j});
            }
            if(forest[i][j] == 'S') {
                s_c = {i, j};
            }
            if(forest[i][j] == 'D') {
                d_c = {i, j};
            }
        }
    }
}

void bfs(bool is_water) {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if((is_water && forest[nx][ny] == 'D') ||
                forest[nx][ny] == 'X' || dist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

void solve() {
    for (auto &it : flow) {
        dist[it.X][it.Y] = 0;
        Q.push(it);
    }
    bfs(true);
    
    dist[s_c.X][s_c.Y] = 0;
    Q.push(s_c);
    bfs(false);

    int res = dist[d_c.X][d_c.Y];
    
    if (res == MAX) cout << "KAKTUS" << '\n';
    else cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}
