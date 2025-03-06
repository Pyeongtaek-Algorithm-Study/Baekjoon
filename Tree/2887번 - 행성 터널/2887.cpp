#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > v;
vector<pair<int, int> > X;
vector<pair<int, int> > Y;
vector<pair<int, int> > Z;
int parents[100001];

void input() {
    cin >> n;
    for(int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
    for(int i = 0; i < n; i++) {
        parents[i] = i;
    }
}

int Find(int x) {
    if(x == parents[x]) return x;
    return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parents[b] = a;
}

void solve() {
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    
    for(int i = 0; i < n - 1; i++) {
        v.push_back({X[i+1].first - X[i].first, X[i].second, X[i+1].second});
        v.push_back({Y[i+1].first - Y[i].first, Y[i].second, Y[i+1].second});
        v.push_back({Z[i+1].first - Z[i].first, Z[i].second, Z[i+1].second});
    }
    sort(v.begin(), v.end());
    
    int edge_cnt = 0;
    int min_weight = 0;
    
    for(int i = 0; i < v.size(); i++) {
        vector<int> edge = v[i];
        int a = edge[1];
        int b = edge[2];
        int weight = edge[0];
        
        if(Find(a) == Find(b)) continue;
        Union(a, b);
        
        min_weight += weight;
        
        if(++edge_cnt == n - 1) break;
    }
    cout << min_weight << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}