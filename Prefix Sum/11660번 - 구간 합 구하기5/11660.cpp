#include <iostream>

using namespace std;

#define MAX 1025

int n, m;
int graph[MAX][MAX];
int dp[MAX][MAX];

void debugging() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }   
}

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            dp[i][j] = graph[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    // debugging();
}

void solve() {
    int x1, x2, y1, y2;
    while(m--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1] << "\n";
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