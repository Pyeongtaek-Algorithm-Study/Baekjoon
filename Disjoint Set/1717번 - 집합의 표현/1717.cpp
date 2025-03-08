#include <iostream>

using namespace std;

#define MAX 1000001

int n, m;
int parents[MAX];

void input() {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parents[i] = i;
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
    for(int i = 0, s, a, b; i < m; i++) {
        cin >> s >> a >> b;
        if(s) cout << (Find(a) == Find(b) ? "YES" : "NO") << '\n';
        else Union(a, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}