#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

int n, m;
int num[2001];
vector<pair<int, int> > qes;
bool dp[2001][2001];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    
    cin >> m;
    for(int i = 0, s, e; i < m; i++) {
        cin >> s >> e;
        qes.push_back({s, e});
    }
}

void solve() {
    fill_n(&dp[0][0], n * n, false);
    
    for(int i = 0; i < n; i++) dp[i][i] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i + 1 == j && num[i] == num[j]) dp[i][j] = true;
        }
    }
    for(int i = 2; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(num[j] == num[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = true;
        }
    }
    
    for(auto &it : qes) {
        dp[it.X - 1][it.Y - 1] ? cout << 1 << '\n' : cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}