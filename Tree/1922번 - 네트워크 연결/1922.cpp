#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > networks;
int parents[1001] = { 0, };

void input() {
    cin >> n >> m;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        networks.push_back({c, a, b});
    }
    
    for(int i = 1; i <= n; i++) parents[i] = i;
}

int Find(int a) {
    if(parents[a] == a) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parents[b] = a;
}

void solve() {
    sort(networks.begin(), networks.end());
    
    int net_cnt = 0, net_weight = 0;
    for(auto &net : networks) {
        int st = net[1], end = net[2];
        if(Find(st) == Find(end)) continue;
        
        Union(st, end);
        net_weight += net[0];
        
        if(++net_cnt == n - 1) break;
    }
    
    cout << net_weight << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}