#include <iostream>

using namespace std;

#define LIM 17

int n, ans = 0;
int home[LIM][LIM] = { 0, };
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> home[i][j];
        }
    }
}

void dfs(int x, int y, int pipe) {
    if(x == n - 1 && y == n - 1) {
        ans++;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        if(pipe == 0 && i == 2) continue;
        else if(pipe == 2 && i == 0) continue;
        else if(i == 1 && (home[x + 1][y] || home[x][y + 1])) continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && !home[nx][ny]) {
            dfs(nx, ny, i);
        }
    }
}

void solve() {
    dfs(0, 1, 0);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}