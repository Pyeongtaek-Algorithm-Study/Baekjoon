#include <iostream>
#include <queue>

using namespace std;

#define MAX 101
#define X first
#define Y second

int n, m, k;
int street[MAX][MAX];
int vis[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

queue<pair<int, int> > q;
int area = 0;

void BFS() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vis[cur.X][cur.Y] = 1;
        area++;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!street[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while(k--) {
        int r, c;
        cin >> r >> c;
        street[r-1][c-1] = 1;
    }
    
    int M = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            area = 0;
            if(street[i][j] && !vis[i][j]) {
                q.push({i, j});
                BFS();
            }
            M = max(M, area);
        }
    }
    
    cout << M << "\n";

    return 0;
}
