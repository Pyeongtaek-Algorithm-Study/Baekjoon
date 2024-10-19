#include <iostream>
#include <vector>

using namespace std;

int t;
vector<string> dp[12];

void input() {
    cin >> t;
}

void solve() {
    dp[1] = {"1"};
    dp[2] = {"1+1", "2"};
    dp[3] = {"1+1+1", "1+2", "2+1", "3"};
    
    for(int i = 4; i < 12; i++) {
        for(int j = 1; j <= 3; j++) {
            for(const string &it : dp[i-j]) {
                dp[i].push_back(it + "+" + to_string(j));
            }
        }
    }
    
    while(t--) {
        int n;
        cin >> n;
        cout << "Answer: " << dp[n].size() << '\n';
        for(const auto &it : dp[n]) cout << it << " ";
        cout << "\n\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
