#include <iostream>
#include <queue>

using namespace std;

#define LIM 51
#define X first
#define Y second

int n, m, ans;
char map[LIM][LIM];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            map[i][j] = str[j];
        }
    }
}

void bfs(int x, int y) {
    int vis[LIM][LIM] = { 0, };
    queue<pair<int, int> > Q;
    Q.push({x, y});
    vis[x][y] = 1;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        ans = max(ans, vis[cur.X][cur.Y] - 1);
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];    
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || map[nx][ny] == 'W') continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'L') bfs(i, j);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}