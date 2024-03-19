#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX 301

int t, l;
int kx, ky;
int gx, gy;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int> > Q;


void input() {
    cin >> l;
    cin >> kx >> ky;
    cin >> gx >> gy;
}

void reset() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            board[i][j] = 0;
            vis[i][j] = false;
        }
    }
    while(!Q.empty()) Q.pop();
}

void solve() {
    Q.push({kx, ky});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X][cur.Y] = true;   
        if(cur.X == gx && cur.Y == gy) {
            break;
        }
        for(int i = 0; i < 8; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if( vis[nx][ny] ) continue;
            vis[nx][ny] = true;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << board[gx][gy] << "\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i++) {
        reset();
        input();
        solve();
    }
    
    return 0;
}