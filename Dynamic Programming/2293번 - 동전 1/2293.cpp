#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coin;
int dp[10001] = { 0, };

void input() {
    cin >> n >> k;
    coin.resize(n);
    
    for(int i = 0; i < n; i++) cin >> coin[i];
}

void solve() {
    // 자신의 코인일 때 경우의 수를 넣기 위해
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    
    cout << dp[k] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}