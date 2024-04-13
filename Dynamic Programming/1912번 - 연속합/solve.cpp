#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int dp[100001];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i = 0;i < n;i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

    int M = dp[0];
    int tmp;
    for(int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        M = max(M, dp[i]);
    }

    cout << M << '\n';
	return 0;
}
