#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n;
vector<pair<ll, ll> > ingre;
int vis[11];
int ans = 1e9;

void input() {
    cin >> n;
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        ingre.push_back({a, b});
    }
}

void dfs(ll a, ll b, int cnt) {
    for(int i = cnt; i < ingre.size(); i++) {
        if(vis[i]) continue;
        
        int na = a * ingre[i].first;
        int nb = b + ingre[i].second;
        ans = min(ans, abs(na - nb));
        
        vis[i] = 1;
        dfs(na, nb, i);
        vis[i] = 0;
        na /= ingre[i].first;
        nb -= ingre[i].second;
    }
}

void solve() {
    dfs(1, 0, 0);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}