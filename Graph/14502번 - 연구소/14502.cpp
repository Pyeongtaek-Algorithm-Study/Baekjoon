#include <iostream>

using namespace std;

int n, m;
int lab[8][8] = { 0, };
int after_lab[8][8] = { 0, };
bool vis[8][8] = { false, };
int safe_zone = 0;
int ans = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }
}

void make_wall(int one, int two, int thr) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            after_lab[i][j] = lab[i][j];
        }
    }
    after_lab[one/m][one%m] = 1;
    after_lab[two/m][two%m] = 1;
    after_lab[thr/m][thr%m] = 1;
}

void dfs(int r, int c) {
    vis[r][c] = true;
    after_lab[r][c] = 2;
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && after_lab[nr][nc] != 1) {
            dfs(nr, nc);
        }
    }
}

void spread_virus() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(after_lab[i][j] == 2 && !vis[i][j]) {
                dfs(i, j);
            }
        }
    }
}

void find_safe() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!after_lab[i][j]) {
                safe_zone++;
            }
        }
    }
    ans = max(ans, safe_zone);
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }
    safe_zone = 0;
}

void solve() {
    for(int i = 0; i < n * m; i++) {
        if(lab[i/m][i%m]) continue;
        for(int j = i + 1; j < n * m; j++) {
            if(lab[j/m][j%m]) continue;
            for(int k = j + 1; k < n * m; k++) {
                if(lab[k/m][k%m]) continue;
                make_wall(i, j, k);
                spread_virus();
                find_safe();
                init();
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();

    return 0;
}