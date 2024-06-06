// 2573번 : 빙산
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define MAX 301
#define X first
#define Y second

int n, m;
int arr[MAX][MAX];
int vis[MAX][MAX];
int tmp[MAX][MAX];
int year = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q;

void input() {
    cin >> n >> m;
    for(int i = 0; i <n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

void bfs() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vis[cur.X][cur.Y] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!arr[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void dfs(pair<int, int> c) {
    vis[c.X][c.Y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = c.X + dx[i];
        int ny = c.Y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!arr[nx][ny] || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs({nx, ny});
    }
}

void solve() {
    while(1) {
        int iceberg = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] && !vis[i][j]) {
                    iceberg++;
                    // q.push({i, j});
                    // bfs();
                    dfs({i, j});
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        if(iceberg != 1) {
            cout << ((iceberg >= 2) ? year : 0);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j]) {
                    int sea = 0;
                    for(int k = 0; k <4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(!arr[nx][ny]) sea++;
                    }
                    tmp[i][j] = max(arr[i][j] - sea, 0);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
        year++;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}