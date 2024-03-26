#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A;
int arr[201];
int dp[201];

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

    cout << N - dp[N-1] << '\n';
    return 0;
}
