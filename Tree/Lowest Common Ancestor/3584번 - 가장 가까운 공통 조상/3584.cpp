#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

int t, n, m;
int parents[MAX];
vector<int> v[MAX];

void input() {
    for(int i = 0; i < MAX; i++) v[i].clear();
    for(int i = 1; i <= n; i++) parents[i] = i;
    
    cin >> n;
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        parents[b] = a;
    }
}

int lca(int x, int y) {
    bool vis[MAX] = { false, };
    vis[x] = true;
    
    while(x != parents[x]) {
        x = parents[x];
        vis[x] = true;
    }
    while(!vis[y]) {
        y = parents[y];
    }
    
    return y;
}

void solve() {
    int u, v;
    cin >> u >> v;
    
    cout << lca(u, v) << '\n';
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
