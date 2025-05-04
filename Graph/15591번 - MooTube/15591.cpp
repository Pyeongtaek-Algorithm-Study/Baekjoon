#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, q;
vector<pair<int, int> > edges[5001];
vector<pair<int, int> > output;

void input() {
    cin >> n >> q;
    for(int i = 0, p, q, r; i < n - 1; i++) {
        cin >> p >> q >> r;
        edges[p].push_back({q, r});
        edges[q].push_back({p, r});
    }
    
    for(int i = 0, k , v; i < q; i++) {
        cin >> k >> v;
        output.push_back({k , v});
    }
}

int bfs(int k, int v) {
    int vis[5001] = { 0, };
    queue<int> Q;
    Q.push(v);
    
    int cnt = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        vis[cur] = 1;
        
        for(int i = 0; i < edges[cur].size(); i++) {
            int nxt = edges[cur][i].X;
            int usado = edges[cur][i].Y;
            
            if(vis[nxt] || usado < k) continue;
            
            cnt++;
            vis[nxt] = 1;
            Q.push(nxt);
        }
    }
    
    return cnt;
}

void solve() {
    int ans = 0;
    
    for(auto &op : output) {
        ans = bfs(op.first, op.second);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}