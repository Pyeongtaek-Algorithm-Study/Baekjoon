#include <bits/stdc++.h>

using namespace std;

int arr[301], dp[301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];
    dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]);

    for(int i=3;i<N;i++) {
        dp[i] = max(arr[i]+arr[i-1]+dp[i-3], arr[i]+dp[i-2]);
    }

    cout << dp[N-1] << '\n';

    return 0;
}
