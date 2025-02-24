#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50001

int n, m;
vector<int> edge[MAX];
int parents[MAX], depth[MAX];
int vis[MAX];


void input() {
    cin >> n;
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void dfs(int node, int dep) {
    vis[node] = true;
    depth[node] = dep;
    
    for(int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i];
        if(!vis[next_node]) {
            parents[next_node] = node;
            dfs(next_node, dep + 1);
        }
    }
}

int lca(int node_a, int node_b) {
    if(depth[node_a] > depth[node_b]) swap(node_a, node_b);
    
    while(depth[node_a] != depth[node_b]) {
        node_b = parents[node_b];
    }
    
    while(node_a != node_b) {
        node_a = parents[node_a];
        node_b = parents[node_b];
    }
    
    return node_a;
}

void solve() {
    dfs(1, 0);
    
    cin >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}