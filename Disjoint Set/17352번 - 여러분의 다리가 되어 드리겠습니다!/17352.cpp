#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > bridges;
int parents[300001];

void input() {
    cin >> n;
    for(int i = 0, a, b; i < n - 2; i++) {
        cin >> a >> b;
        bridges.push_back({a, b});
    }
    
    for(int i = 0; i <= n; i++) {
        parents[i] = i;
    }
}

int Find(int a) {
    if(a == parents[a]) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parents[b] = a;
}

void solve() {
    for(auto &bridge : bridges) {
        if(bridge.first > bridge.second) swap(bridge.first, bridge.second);
        Union(bridge.first, bridge.second);
    }
    
    for(int i = 2; i <= n; i++) {
        if(Find(1) != Find(i)) {
            cout << 1 << ' ' << i << '\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}