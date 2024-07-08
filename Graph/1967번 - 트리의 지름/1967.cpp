#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

int n;
int vis[MAX] = { 0, };
vector<pair<int, int> > v[10001];
int long_node, far;


void input() {
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void dfs(int ariv, int dis) {
    vis[ariv] = 1;
    if(dis > far) {
        long_node = ariv;
        far = dis;
    }
    for(int i = 0; i < v[ariv].size(); i++) {
        if(!vis[v[ariv][i].first]) {
            dfs(v[ariv][i].first, v[ariv][i].second + dis);
        }
    }
}

void solve() {
    dfs(1, 0);
    far = 0;
    fill(vis, vis + n + 1, 0);
    dfs(long_node, 0);
    cout << far << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}