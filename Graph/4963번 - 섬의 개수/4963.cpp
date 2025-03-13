#include <iostream>

using namespace std;

int w, h;
int map[51][51] = { 0, };
int vis[51][51] = { 0, };

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void input() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }
    fill_n(&vis[0][0], 51 * 51, 0);
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(map[nx][ny] && !vis[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

void solve() {
    int ans = 0;
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1 && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        cin >> w >> h;
        if(!w || !h) break;
        input();
        solve();
    }
    
    return 0;
}