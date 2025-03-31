#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, w;
int sp_tm[1001];
int res_tm[1001];
int indegree[1001];
vector<int> g[1001];

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> sp_tm[i];
        res_tm[i] = sp_tm[i];
    }
    for(int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y]++;
    }
    cin >> w;
}

void solve() {
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) Q.push(i);
    }
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        for(int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i];
            res_tm[next] = max(res_tm[next], res_tm[cur] + sp_tm[next]);
            if(--indegree[next] == 0) Q.push(next);
        }
    }
    cout << res_tm[w] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        input();
        solve();
        for(int i = 1; i <= n; i++) g[i].erase(g[i].begin(), g[i].end());
    }
    
    return 0;
}