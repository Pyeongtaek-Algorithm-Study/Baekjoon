#include <iostream>

using namespace std;

#define LIM 501

int n, m;
int paper[LIM][LIM] = { 0, };
bool vis[LIM][LIM] = { false, };
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int ans = 0;

void back(int x, int y, int cnt, int sum) {
    if(cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    
    if(!vis[x][y]) {
        vis[x][y] = true;
        sum += paper[x][y];
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny]) {
                back(nx, ny, cnt + 1, sum);
            }
        }
        vis[x][y] = false;
    }
}

void t(int x, int y) {
    for(int dir = 0; dir < 4; dir++) {
        int t_sum = paper[x][y];
        
        for(int i = 0; i < 4; i++) {
            // 상하좌우중 1개씩을 건너뜀
            if(i == dir) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m) t_sum += paper[nx][ny];
        }
        ans = max(ans, t_sum);
    }
}

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            back(i, j, 0, 0);
            t(i, j);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}