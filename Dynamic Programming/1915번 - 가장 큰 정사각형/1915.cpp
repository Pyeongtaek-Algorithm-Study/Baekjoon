#include <iostream>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];
int max_side;

void input() {
    cin >> n >> m;
    
    fill_n(&arr[0][0], 1001 * 1001, 0);
    fill_n(&dp[0][0], 1001 * 1001, 0);
    
    string num;
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        for(int j = 0; j < m; j++) {
            arr[i][j] = num[j] - '0';
        }
    }
}

int area(int i, int j) {
    int side = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
    max_side = max(max_side, side);
    return side;
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j]) {
                dp[i+1][j+1] = area(i+1, j+1);
            }
        }
    }
    
    cout << max_side * max_side << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}