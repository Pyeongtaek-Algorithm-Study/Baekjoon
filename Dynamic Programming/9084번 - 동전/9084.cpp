#include <iostream>

using namespace std;

int t, c, m;
int coin[21] = { 0, };

void input() {
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> coin[i];
    }
    cin >> m;
}

void solve() {
    int dp[10001] = { 0, };
    dp[0] = 1;
    
    for(int i = 0; i < c; i++) {
        for(int j = coin[i]; j <= m; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    
    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    
    return 0;
}