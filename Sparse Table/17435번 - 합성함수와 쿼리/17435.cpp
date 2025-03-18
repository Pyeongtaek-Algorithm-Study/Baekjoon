#include <iostream>
#include <vector>

using namespace std;

#define LIM 200001

int m, q;
// 200001 < 2^20
int num[LIM][20];

void input() {
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> num[i][0];
    }
}

void sparse_table(int n) {
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= m; i++) {
            // 정점 i에서 2^j번 이동한 후의 정점
            num[i][j] = num[num[i][j-1]][j-1]; 
        }
    }
}

void solve() {
    sparse_table(20);
    cin >> q;
    
    for(int i = 0, n, x; i < q; i++) {
        cin >> n >> x;
        for(int i = 0; 0 < n; i++) {
            if(n & 1) x = num[x][i];
            n >>= 1;
        }
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}