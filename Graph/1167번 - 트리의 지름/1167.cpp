#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001
#define X first
#define Y second

int n;
vector<pair<int, int> > v[MAX];
int vis[MAX] = { 0, };
int dis = 0, long_node = 1;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int st, node, cost;
        cin >> st;
        while(1) {
            cin >> node;
            if(node == -1) break;
            cin >> cost;
            v[st].push_back({node, cost});
        }
    }
}

void dfs(int cur, int cnt) {
    vis[cur] = 1;
    if(dis < cnt) {
        dis = cnt;
        long_node = cur;
    }
    for(auto p : v[cur]) {
        if(vis[p.X]) continue;
        dfs(p.X, p.Y + cnt);
    }
}

void solve() {
    dfs(1, 0);
    
    fill(vis, vis + MAX, 0);
    dis = 0;

    dfs(long_node, 0);

    cout << dis << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}