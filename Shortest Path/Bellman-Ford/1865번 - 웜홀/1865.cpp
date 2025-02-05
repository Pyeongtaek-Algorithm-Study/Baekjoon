#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int t, n, m, w;
vector<vector<int> > edges;
int dist[501];

void input() {
    cin >> n >> m >> w;
    int st, ed, cost;
    
    edges.clear();
    for(int i = 0; i < m; i++) {
        cin >> st >> ed >> cost;
        edges.push_back({st, ed, cost});
        edges.push_back({ed, st, cost});
    }
    for(int i = 0; i < w; i++) {
        cin >> st >> ed >> cost;
        edges.push_back({st, ed, -cost});
    }
}

string bellmanford(int start) {
    dist[start] = 0;
    
    for(int i = 0; i < n; i++) {
        for(auto &edge : edges) {
            int cur_node = edge[0], next_node = edge[1], edge_cost = edge[2];
            
            if(dist[cur_node] + edge_cost < dist[next_node]) {
                dist[next_node] = dist[cur_node] + edge_cost;
            }
        }
    }
    
    for(auto &edge : edges) {
        int cur_node = edge[0], next_node = edge[1], edge_cost = edge[2];
        
        if(dist[cur_node] + edge_cost < dist[next_node]) {
            return "YES";
        }
    }
    
    return "NO";
}

void solve() {
    fill_n(&dist[0], 501, INF);
    cout << bellmanford(1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    
    return 0;
}