#include <iostream>
#include <queue>

using namespace std;

#define LIM 101
#define X first
#define Y second

int n, m;
int map[LIM][LIM] = { 0, };
int vis[LIM][LIM] = { 0, };
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void input() {
    // 가로, 세로
    cin >> m >> n;
    string st;
    
    for(int i = 0; i < n; i++) {
        cin >> st;
        for(int j = 0; j < m; j++) {
            map[i][j] = st[j] - '0';
            vis[i][j] = 1e9;
        }
    }
}

void bfs() {
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    vis[0][0] = 0;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(map[nx][ny] == 0 && (vis[nx][ny] > vis[cur.X][cur.Y])) {
                vis[nx][ny] = vis[cur.X][cur.Y];
                Q.push({nx, ny});
            }
            else if(map[nx][ny] == 1 && (vis[nx][ny] > vis[cur.X][cur.Y] + 1)) {
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>> > pq;
    pq.push({0, {0, 0}});
    
    vis[0][0] = 0;
    
    while(!pq.empty()) {
        int cost = -pq.top().X;
        int x = pq.top().Y.X, y = pq.top().Y.Y;
        pq.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(vis[nx][ny] > vis[x][y] + map[nx][ny]) {
                vis[nx][ny] = vis[x][y] + map[nx][ny];
                pq.push({-vis[nx][ny], {nx, ny}});
            }
        }
    }
}

void solve() {
    bfs();
    // dijkstra();
    
    cout << vis[n - 1][m - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}