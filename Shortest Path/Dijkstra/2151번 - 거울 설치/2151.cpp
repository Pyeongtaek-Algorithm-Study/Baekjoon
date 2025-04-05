#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INF 1e9

int n;
char home[51][51];
int vis[51][51][4] = { 0, };
vector<pair<int, int> > door;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            home[i][j] = s[j];
            if(home[i][j] == '#') door.push_back({i, j});
        }
    }
    
    fill_n(&vis[0][0][0], 51 * 51 * 4, INF);
}

void solve() {
    // 시작 점에서 탐색 4방향
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    for(int i = 0; i < 4; i++) pq.push({0, i, door[0].X, door[0].Y});
    
    while(!pq.empty()) {
        int cnt = pq.top()[0];
        int d = pq.top()[1];
        int x = pq.top()[2], y = pq.top()[3];
        pq.pop();
        
        if(x == door[1].X && y == door[1].Y) {
            cout << cnt << '\n';
            break;
        }
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || home[nx][ny] == '*') continue;
        
        // 다음 칸의 현재 방향대로 거울 개수가 더 낮을 때
        if(vis[nx][ny][d] > cnt) {
            vis[nx][ny][d] = cnt;
            pq.push({cnt, d, nx, ny});
        }
        
        // 다음 칸에서 거울을 설치할 수 있는 경우
        if(home[nx][ny] == '!') {
            int ld = (d + 3) % 4, rd = (d + 1) % 4;
            
            // 거울 설치할 수 있는 칸에서 좌측으로 갈 때 거울 개수가 더 낮을 때
            if(vis[nx][ny][ld] > cnt + 1) {
                vis[nx][ny][ld] = cnt + 1;
                pq.push({cnt + 1, ld, nx, ny});
            }
            // 거울 설치할 수 있는 칸에서 우측으로 갈 때 거울 개수가 더 낮을 때
            if(vis[nx][ny][rd] > cnt + 1) {
                vis[nx][ny][rd] = cnt + 1;
                pq.push({cnt + 1, rd, nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}