// 1932번: 정수 삼각형
#include <iostream>

using std::cin;
using std::cout;
using std::ios;
using std::max;

#define MAX 501

int arr[MAX][MAX];
int dp[MAX][MAX];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }
}


void solution() {
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[n-1][i]);
    }
    
    cout << ans << '\n';
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    
    return 0;
}