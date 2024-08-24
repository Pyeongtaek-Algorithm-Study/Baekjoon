#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101
#define X first
#define Y second
int m, n, k;
int cnt;
vector<int> res;
// int board[MAX][MAX];b
bool vis[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
    cin >> m >> n >> k;
    int x1, x2, y1, y2;
    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int a = y1; a < y2; a++) {
            for(int b = x1; b < x2; b++) {
                vis[a][b] = true;
            }
        }
    }
}

void dfs(int r, int c) {
    vis[r][c] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

void solve() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(int it : res) cout << it << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}