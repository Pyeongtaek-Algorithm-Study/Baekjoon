//2458번: 키 순서
#include <iostream>

using namespace std;

int n, m;
int stu[501][501];

void input() {
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        stu[a][b] = 1;
        stu[b][a] = -1;
    }
}

void solve() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(stu[i][k] == stu[k][j] && stu[i][k] != 0) stu[i][j] = stu[i][k];
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        int cnt = n - 1;
        for(int j = 1; j <= n; j++) {
            if(stu[i][j] != 0) cnt--;
        }
        if(cnt == 0) ans++;
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