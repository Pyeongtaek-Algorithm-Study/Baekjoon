#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A;
int arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A;
        arr[i] = A;
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
    }
    sort(dp, dp+N);

    cout << dp[N-1];
    return 0;
}
