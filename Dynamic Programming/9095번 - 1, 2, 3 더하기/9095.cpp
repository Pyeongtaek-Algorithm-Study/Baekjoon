#include <iostream>

using namespace std;

int t;
int dp[12];

void input() {
    cin >> t;
}

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 12; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}