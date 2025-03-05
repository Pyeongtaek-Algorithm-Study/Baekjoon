#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int n, m;
int bus[101][101] = { 0, };
vector<int> path[101][101];

void input() {
    cin >> n >> m;
    
    fill_n(&bus[0][0], 101 * 101, INF);
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
        path[a][b].clear();
        path[a][b].push_back(a);
        path[a][b].push_back(b);
    }
}

void print_ans() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (bus[i][j] == INF ? 0 : bus[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(bus[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }
            cout << path[i][j].size() << ' ';
            for(auto &it : path[i][j]) cout << it << ' ';
            cout << '\n';
        }
    }
}

void solve() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if((bus[i][k] && bus[k][j]) && (bus[i][j] > bus[i][k] + bus[k][j])) {
                    bus[i][j] = bus[i][k] + bus[k][j];
                    
                    path[i][j].clear();
                    path[i][j].insert(path[i][j].end(), path[i][k].begin(), path[i][k].end() - 1);
                    path[i][j].insert(path[i][j].end(), path[k][j].begin(), path[k][j].end());
                }
            }
        }
    }
    
    print_ans();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}