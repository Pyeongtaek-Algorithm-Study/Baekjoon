#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[16];
int ans;
vector<pair<int, int> > v;

void dynamicP(int n) {
    for(int i = n; i >= 0; i--) {
        if(i + v[i].first > n + 1) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], v[i].second + dp[i + v[i].first]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i<N; i++) {
        int t, p;
        cin >> t >> p;
        v.push_back({t, p});
    }
    
    dynamicP(N-1);
    cout << dp[0];    

    return 0;
}
