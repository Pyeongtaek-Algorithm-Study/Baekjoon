#include <iostream>
#include <vector>

using namespace std;

#define INF 1e10

int n, m;
vector<vector<int> > edges;
long long min_cost[501];

void input() {
    cin >> n >> m;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    
    fill_n(&min_cost[0], 501, INF);
}

void solve() {
    min_cost[1] = 0;
    
    for(int i = 0; i < n; i++) {
        for(auto &edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            
            if(min_cost[from] == INF || min_cost[to] < min_cost[from] + cost) continue;
            min_cost[to] = min_cost[from] + cost;
        }
    }
    
    for(auto &edge : edges) {
        int from = edge[0], to = edge[1], cost = edge[2];
        
        if(min_cost[from] != INF && min_cost[to] > min_cost[from] + cost) {
            cout << -1 << '\n';
            exit(0);
        }
    }
    
    for(int i = 2; i <= n; i++) cout << (min_cost[i] == INF ? -1 : min_cost[i]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}