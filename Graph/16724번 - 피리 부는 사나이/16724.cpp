#include <iostream>

using namespace std;

int n, m;
char board[1001][1001];
int vis[1001][1001];
int ans = 1;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            board[i][j] = str[j];
        }
    }
}

void show() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "ans : " << ans << "\n\n";
}

void dfs(int x, int y) {
    vis[x][y] = ans;
    int nx = x;
    int ny = y;
    // show();
    if(board[x][y] == 'U') {
        nx -= 1;
    }
    else if(board[x][y] == 'D') {
        nx += 1;
    }
    else if(board[x][y] == 'L') {
        ny -= 1;
    }
    else if(board[x][y] == 'R'){
        ny += 1;
    }
    
    if(!vis[nx][ny]) {
        dfs(nx, ny);
    }
    else if(vis[nx][ny] == ans) {
        ans++;
    }
    vis[x][y] = vis[nx][ny];
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                dfs(i, j);
            }
        }
    }
    // show();
    cout << ans - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}