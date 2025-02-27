#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define LIM 1001

int n;
int coin[LIM];
bool weight[LIM];

void input() {
    cin >> n;
    for(int i = 0, c; i < n; i++) {
        cin >> coin[i];
    }
}

void solve() {
    ll ans = 1;
    
    sort(coin, coin + n);
    
    for(int i = 0; i < n; i++) {
        if(coin[i] > ans) break;
        ans += coin[i];
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