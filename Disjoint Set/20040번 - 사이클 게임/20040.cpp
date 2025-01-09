#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int> > line;
int parents[500001];
int vis[500001];

void input() {
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        line.push_back({a, b});
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
    for(int i = 0; i < m; i++) {
        if(Find(line[i].first) == Find(line[i].second)) {
            cout << i + 1 << '\n';
            return;
        }

        Union(line[i].first, line[i].second);
    }
    
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}