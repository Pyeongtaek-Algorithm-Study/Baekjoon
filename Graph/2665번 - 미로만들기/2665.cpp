#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MAX 1e9

int n;
int room[51][51];
int vis[51][51];
queue<pair<int, int> > Q;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            room[i][j] = str[j] - '0';
            vis[i][j] = MAX;
        }
    }
}

void BFS() {
    Q.push({0, 0});
    vis[0][0] = 0;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(room[nx][ny] == 1 && vis[nx][ny] > vis[cur.X][cur.Y]) {
                vis[nx][ny] = vis[cur.X][cur.Y];
                Q.push({nx, ny});
            }
            else if(room[nx][ny] == 0 && vis[nx][ny] > vis[cur.X][cur.Y] + 1) {
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
}

void solve() {
    BFS();
    cout << vis[n-1][n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}