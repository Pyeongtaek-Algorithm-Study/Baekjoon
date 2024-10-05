#include <iostream>
#include <queue>

using namespace std;

#define MAX 101
#define X first
#define Y second

int n, m, h;
int warehouse[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];
queue<pair<int, pair<int, int>> > Q;
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int res = 0;

void input() {
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> warehouse[i][j][k];
                if(warehouse[i][j][k] == 1) Q.push({i, {j, k}});
            }
        }
    }
}

void bfs() {
    while(!Q.empty()) {
        pair<int, pair<int, int> > cur = Q.front(); Q.pop();
        vis[cur.X][cur.Y.X][cur.Y.Y] = true;
        for(int i = 0; i < 6; i++) {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            int nz = cur.X + dz[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(warehouse[nz][nx][ny] != 0 || vis[nz][nx][ny]) continue;
            warehouse[nz][nx][ny] = warehouse[cur.X][cur.Y.X][cur.Y.Y] + 1;
            vis[nz][nx][ny] = true;
            Q.push({nz, {nx, ny}});
        }
    }
}

void solve() {
    bfs();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(warehouse[i][j][k] == 0) {
                    cout << -1 << "\n";
                    exit(0);
                }
                res = max(res, warehouse[i][j][k]);
            }
        }
    }
    cout << res - 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}