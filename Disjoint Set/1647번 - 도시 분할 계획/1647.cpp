#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > line;
int parents[200001];

void input() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> tmp = {c, a, b};
        line.push_back(tmp);
    }
    
    for(int i = 0; i < n; i++) {
        parents[i] = i;
    }
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
    sort(line.begin(), line.end());
    
    int node_cnt = 0;
    int ans = 0;
    
    vector<int> w;
    
    for(auto &it : line) {
        if(Find(it[1]) == Find(it[2])) continue;
        Union(it[1], it[2]);
        
        w.push_back(it[0]);
        
        if(++node_cnt == n - 1) break;
    }
    
    for(int i = 0; i < w.size() - 1; i++) {
        ans += w[i];
    }
    
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}