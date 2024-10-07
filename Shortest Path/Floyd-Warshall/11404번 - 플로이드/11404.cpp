#include <iostream>
#include <vector>

using namespace std;

#define MAX 987654321

int n, m;
int map[101][101];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) map[i][j] = 0;
            else map[i][j] = MAX;
        }
    }
    int st, end, cost;
    while(m--) {
        cin >> st >> end >> cost;
        map[st][end] = min(map[st][end], cost);
    }
}

void solve() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == MAX) cout << 0 << " ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}