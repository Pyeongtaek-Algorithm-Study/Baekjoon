#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;
int map[1001][1001];
int vis[2][1001][1001];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }
}

int bfs() {
    queue<pair<pair<int, int>, int> > Q;
    Q.push({{0, 0}, 0});
    vis[0][0][0] = 1;
    
    while(!Q.empty()) {
        pair<pair<int, int>, int> cur = Q.front(); Q.pop();
        
        if(cur.X.X == n - 1 && cur.X.Y == m - 1) return vis[cur.Y][cur.X.X][cur.X.Y];
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0 && vis[cur.Y][nx][ny] == 0) {
                vis[cur.Y][nx][ny] = vis[cur.Y][cur.X.X][cur.X.Y] + 1;
                Q.push({{nx, ny}, cur.Y});
            }
            if(map[nx][ny] == 1 && cur.Y == 0) {
                vis[cur.Y + 1][nx][ny] = vis[cur.Y][cur.X.X][cur.X.Y] + 1;
                Q.push({{nx, ny}, cur.Y + 1});
            }
        }
    }
    
    return -1;
}

void solve() {
    cout << bfs() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}