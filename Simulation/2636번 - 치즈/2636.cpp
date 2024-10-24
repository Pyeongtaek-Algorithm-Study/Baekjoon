#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;
int cheese[105][105];
int day = 0;
int leaving = 0;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};
bool vis[101][101];
queue<pair<int, int> > Q;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cheese[i][j] == 2) cheese[i][j] = 0;
            vis[i][j] = false;
        }
    }
    leaving = 0;
}

void bfs() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        cheese[cur.X][cur.Y] = 2;
        vis[cur.X][cur.Y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 미리 범위를 체크
            if(cheese[nx][ny] == 1) cheese[nx][ny] = 2;
            if(cheese[nx][ny] == 2 || cheese[nx][ny] == 1 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

void solve() {
    int result = 0;
    while(true) {
        int finish = 0;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(cheese[i][j] == 1) {
                    leaving++;
                    finish = 1; 
                }
            }
        }
        Q.push({0, 0});
        bfs();
        if(!finish) break;
        result = leaving;
        day++;
        init();
    }
    cout << day << '\n' << result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    
    return 0;
}