#include <iostream>

using namespace std;

int n;
int forest[501][501] = { 0, };
int dp[501][501] = { 0, };

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <n; j++) {
            cin >> forest[i][j];
        }
    }
}

int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && forest[nx][ny] > forest[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1 );
        }
    }
    
    return dp[x][y];
}

void solve() {
    int result = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <n; j++) {
            result = max(result, dfs(i, j));
        }
    }
    
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}