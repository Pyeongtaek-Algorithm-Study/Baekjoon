//10159번: 저울
#include <iostream>

using namespace std;

int n, m;
int goods[101][101];

void input() {
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        goods[a][b] = 1;
        goods[b][a] = -1;
    }
}

void solve() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(goods[i][k] == goods[k][j] && goods[i][k] != 0) goods[i][j] = goods[i][k];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = n - 1;
        for(int j = 1; j <= n; j++) {
            if(goods[i][j] != 0) cnt--;
        }
        cout << cnt << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}