// 2133번: 타일 채우기
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 501

int n;
int dp[31];

void input() {
    cin >> n;
}

void solve() {
    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= n; i++) {
        for(int j = i; j >= 0; j -= 2) dp[i] += dp[j-4]*2;
        dp[i] += dp[i-2] * 3;
        // dp[i] = dp[i-2] * 4 - dp[i-4];
        // dp[i] = dp[i-2] * 3 + dp[i-4] * 2 + ... + 2;
        //       = dp[i-2] * 3 + (dp[i-4] - dp[i-4]) + dp[i-4] * 2 + ... + 2;
        //       = dp[i-2] * 3 + (dp[i-4] * 3 + ... + 2) - dp[i-4];
        //       = dp[i-2] * 3 + dp[i-2] - dp[i-4];
        //       = dp[i-2] * 4 - dp[i-4];
    }
    
    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}