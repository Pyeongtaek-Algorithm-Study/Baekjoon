#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 21
#define X first
#define Y second
#define BIG_NUM 1e9

int w, h;
char board[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
pair<int, int> robot;
vector<pair<int, int>> dust;

void input() {
    dust.clear();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'o') robot = {i, j};
            if(board[i][j] == '*') dust.push_back({i, j});
        }
    }
}

int bfs(char board[MAX][MAX], pair<int, int> s, pair<int, int> d) {
    int vis[MAX][MAX] = { 0, };
    queue<pair<int, int> > Q;
    Q.push(s);
    vis[s.X][s.Y] = 1;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(board[nx][ny] == 'x' || vis[nx][ny]) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    
    return (vis[d.X][d.Y] == 0 ? -1 : vis[d.X][d.Y] - 1);
}

void solve() {
    int ans = BIG_NUM;
    int m[MAX][MAX][MAX][MAX] = { 0, };

    do {
        pair<int, int> tr = robot;
        char tmp[MAX][MAX];

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        
        int move = 0;
        for(int i = 0; i < dust.size(); i++) {
            tmp[dust[i].X][dust[i].Y] = 'o';
            tmp[tr.X][tr.Y] = '.';
            
            if(m[tr.X][tr.Y][dust[i].X][dust[i].Y] == 0) {
                int dist = bfs(tmp, tr, dust[i]);
                m[tr.X][tr.Y][dust[i].X][dust[i].Y] = dist;

                if(dist == -1) {
                    move = BIG_NUM;
                    break;
                }
                
                move += dist;
            }
            else {
                if(m[tr.X][tr.Y][dust[i].X][dust[i].Y] == -1) {
                    move = BIG_NUM;
                    break;
                }
                
                move += m[tr.X][tr.Y][dust[i].X][dust[i].Y];
            }         
            tr = dust[i];
        }
        
        ans = min(ans, move);
    } while(next_permutation(dust.begin(), dust.end()));

    cout << (ans == BIG_NUM ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> w >> h;
        if(!w && !h) break;

        input();
        solve();
    }
    
    return 0;
}