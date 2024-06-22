#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[3] = {0, }, tmp[3] = {0, }, low_dp[3] = {0, }, high_dp[3] = {0, };

void input() {
    cin >> n;
}

void solve() {
    for(int i = 0; i < n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        
        tmp[0] = high_dp[0];
        tmp[1] = high_dp[1];
        tmp[2] = high_dp[2];
        
        high_dp[0] = max(tmp[0], tmp[1]) + arr[0];
        high_dp[1] = max(max(tmp[0], tmp[1]), tmp[2]) + arr[1];
        high_dp[2] = max(tmp[2], tmp[1]) + arr[2];
        
        tmp[0] = low_dp[0];
        tmp[1] = low_dp[1];
        tmp[2] = low_dp[2];
        
        low_dp[0] = min(tmp[0], tmp[1]) + arr[0];
        low_dp[1] = min(min(tmp[0], tmp[1]), tmp[2]) + arr[1];
        low_dp[2] = min(tmp[2], tmp[1]) + arr[2];
    }
    sort(high_dp, high_dp + 3, greater<int>());
    sort(low_dp, low_dp + 3);
    cout << high_dp[0] << " " << low_dp[0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}