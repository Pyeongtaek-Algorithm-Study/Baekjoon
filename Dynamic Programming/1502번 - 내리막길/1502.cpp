// 1502번: 내리막길
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 501

int n, m;
int arr[MAX][MAX];
int vis[MAX][MAX];
int ans = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            vis[i][j] = -1;
        }
    }
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << setfill(' ') << setw(2) << vis[i][j] << " ";
        }
        cout << '\n';
    }
}

int dfs(int x, int y) {
    if(x == n - 1 && y == m - 1) {
        return 1;
    }
    
    if(vis[x][y] == -1) {
        vis[x][y] = 0;  
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] >= arr[x][y]) continue;
            vis[x][y] += dfs(nx, ny);
        }
    }
    return vis[x][y];
}

void solve() {
    cout << dfs(0, 0) << "\n";
    // print();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}