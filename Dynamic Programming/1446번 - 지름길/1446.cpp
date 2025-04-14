#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int n, d;
vector<vector<int> > v;
int dp[10001] = { 0, };

void input() {
    cin >> n >> d;
    for(int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({b, a, c});
    }
}

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

void solve() {
    for(int i = 0; i <= d; i++) dp[i] = i;
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto &it : v) {
        dp[it[0]] = min(dp[it[0]], dp[it[1]] + it[2]);
        
        for(int j = it[0] + 1; j <= d; j++) {
            dp[j] = min(dp[j], dp[j - 1] + 1);
        }
    }
    
    cout << dp[d] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}