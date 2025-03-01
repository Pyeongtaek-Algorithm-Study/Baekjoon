#include <iostream>
#include <vector>

using namespace std;

int n;
int stock[100001];
vector<int> dp;

void input() {
    for(int i = 0; i < n; i++) {
        cin >> stock[i];
    }
    dp.clear();
}

void solve() {
    int ans = 1;
    dp.push_back(stock[0]);
    
    for(int i = 1; i < n; i++) {
        if(stock[i] > dp.back()) {
            dp.push_back(stock[i]);
            continue;
        }
        int idx = lower_bound(dp.begin(), dp.end(), stock[i]) - dp.begin();
        dp[idx] = stock[i];
    }
    
    cout << dp.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n) {
        input();
        solve();
    }
    
}