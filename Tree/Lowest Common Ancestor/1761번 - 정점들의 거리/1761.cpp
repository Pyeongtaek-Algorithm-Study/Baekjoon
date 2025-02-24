#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 40001
#define X first
#define Y second

int n, m;
vector<pair<int, int> > edge[MAX];
int parents[MAX], depth[MAX], dist[MAX];
int vis[MAX];


void input() {
    cin >> n;
    for(int i = 0, a, b, c; i < n - 1; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
}

void dfs(int node, int dep, int len) {
    vis[node] = true;
    depth[node] = dep;
    dist[node] = len;
    
    for(int i = 0; i < (int)edge[node].size(); i++) {
        int next_node = edge[node][i].X;
        int next_len = len + edge[node][i].Y;
        if(!vis[next_node]) {
            parents[next_node] = node;
            dfs(next_node, dep + 1, next_len);
        }
    }
}

int lca(int node_a, int node_b) {
    int len_a = dist[node_a], len_b = dist[node_b];
    
    if(depth[node_a] > depth[node_b]) swap(node_a, node_b);
    
    while(depth[node_a] != depth[node_b]) {
        node_b = parents[node_b];
    }
    
    while(node_a != node_b) {
        node_a = parents[node_a];
        node_b = parents[node_b];
    }
    
    return len_a + len_b - 2 * dist[node_a];
}

void solve() {
    dfs(1, 0, 0);
    
    cin >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    
    return 0;
}