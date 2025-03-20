#include <iostream>
#include <deque>

using namespace std;

int n, m, k;
int ground[11][11] = { 0, };
int soil[11][11] = { 0, };
deque<int> tree[11][11];

void input() {
    cin >> n >> m >> k;
    for(int i = 0; i < n * n; i++) {
        cin >> soil[i / n][i % n];
        ground[i / n][i % n] = 5;
    }
    
    for(int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        tree[x - 1][y - 1].push_back(z);
    }
}

void spring_summer() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int idx = 0, last_cnt = tree[i][j].size();
            for(; idx < last_cnt; idx++) {
                if(tree[i][j][idx] <= ground[i][j]) {
                    ground[i][j] -= tree[i][j][idx];
                    tree[i][j][idx]++;
                }
                else break;
            }
            
            while(last_cnt-- > idx) {
                ground[i][j] += (tree[i][j][last_cnt] / 2);
                tree[i][j].pop_back();
            }
        }
    }
}

void autumn_winter() {
    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int idx = 0; idx < tree[i][j].size(); idx++) {
                if(tree[i][j][idx] % 5 == 0) {
                    for(int d = 0; d < 8; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        
                        tree[nx][ny].push_front(1);
                    }
                }
            }
            
            ground[i][j] += soil[i][j];
        }
    }
}

void solve() {
    int ans = 0;
    
    while(k--) {
        spring_summer();
        autumn_winter();
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += tree[i][j].size();
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