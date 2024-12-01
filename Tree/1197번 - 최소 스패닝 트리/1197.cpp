#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

int v, e;
vector<vector<int> > tree;
int parents[MAX];

void input() {
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree.push_back({c, a, b});
    }
    
    for(int i = 1; i <= v; i++) parents[i] = i;
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
    sort(tree.begin(), tree.end());
    
    int min_weight = 0;
    int edge_cnt = 0;
    
    for(int i = 0; i < tree.size(); i++) {
        // edge value is weight(c), start(a), end(b)
        vector<int> edge = tree[i];
        
        if(Find(edge[1]) == Find(edge[2])) continue;
        Union(edge[1], edge[2]);
        
        min_weight += edge[0];
        
        if(++edge_cnt == v - 1) break;
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