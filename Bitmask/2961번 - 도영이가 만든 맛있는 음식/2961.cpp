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

void solve() {
    for(int i = 1; i < (1 << n); i++) {
        int a = 1, b = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                a *= ingre[j].first;
                b += ingre[j].second;
            }
        }
        ans = min(ans, abs(a - b));
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