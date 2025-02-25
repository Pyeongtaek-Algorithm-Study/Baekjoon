#include <iostream>

using namespace std;

#define MAX 401
#define INF 1e9

int v, e;
int dist[MAX][MAX] = { 0, };

void input() {
    cin >> v >> e;
    
    fill_n(&dist[0][0], MAX * MAX, INF);
    for(int i = 0, a, b, c; i < e; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
}

void solve() {
    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                if(dist[i][k] && dist[k][j]) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int ans = INF;
    for(int i = 1; i <= v; i++) {
        ans = min(ans, dist[i][i]);
    }
    
    cout << (ans != INF ? ans : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}