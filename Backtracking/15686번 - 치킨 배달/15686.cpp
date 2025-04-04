#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int town[51][51] = { 0, };
int vis[51][51] = { 0, };
vector<pair<int, int> > chicken;
vector<pair<int, int> > home;
bool chi_vis[15] = { false, };
int ans = 1e9;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> town[i][j];
            if(town[i][j] == 1) home.push_back({i, j});
            if(town[i][j] == 2) chicken.push_back({i, j});
        }
    }
}

void backtracking(int cnt, int cur) {
    if(cnt == m) {
        fill_n(&vis[0][0], 51 * 51, 0);
        queue<pair<int, int> > Q;
        
        for(int i = 0; i < chicken.size(); i++) {
            if(chi_vis[i]) {
                Q.push({chicken[i].first, chicken[i].second});
                
                // vis[][]에서 다시 출발 지점으로 방문하는 것을 막기 위함
                vis[chicken[i].first][chicken[i].second] = 1;
            }
        }
        
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = vis[x][y] + 1;
                Q.push({nx, ny});
            }
        }
        
        // 치킨으로부터 집까지 거리들의 합
        int distance = 0;
        for(int i = 0; i < home.size(); i++) {
            // 치킨 집 시작이 1로 시작함으로 1을 뺌
            distance += (vis[home[i].first][home[i].second] - 1);
        }

        ans = min(ans, distance);
    }
    
    for(int nxt = cur; nxt < chicken.size(); nxt++) {
        chi_vis[nxt] = true;
        backtracking(cnt + 1, nxt + 1);
        chi_vis[nxt] = false;
    }
}

void solve() {
    backtracking(0, 0);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}