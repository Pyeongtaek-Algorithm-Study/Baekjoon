#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101
#define X first
#define Y second
int m, n, k;
vector<int> res;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int> > Q;

void input() {
    cin >> m >> n >> k;
    int x1, x2, y1, y2;
    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int a = y1; a < y2; a++) {
            for(int b = x1; b < x2; b++) {
                board[a][b] = 1;
            }
        }
    }
}

int bfs(int r, int c) {
    Q.push({r, c});
    int cnt = 0;
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X][cur.Y] = true;
        cnt++;
    
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    
    return cnt;
}

void solve() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && !board[i][j]) {
                res.push_back(bfs(i, j));
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