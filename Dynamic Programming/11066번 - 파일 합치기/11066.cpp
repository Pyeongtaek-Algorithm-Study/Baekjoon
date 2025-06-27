#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define LIM 501

int novel;
vector<int> pages;
int sum[LIM] = { 0, };
int dp[LIM][LIM] = { 0, };

void input() {
    cin >> novel;
    pages.clear();
    pages.resize(novel + 1);
    
    for (int i = 1; i <= novel; i++) {
        cin >> pages[i];
    }
}

void solve() {
    for(int i = 1; i <= novel; i++) {
        sum[i] = sum[i - 1] + pages[i];
    }
    
    // 임의의 k만큼의 구간
    for (int k = 1; k < novel; k++) {
        // 시작 위치
        for (int st = 1; st + k <= novel; st++) {
            int end = st + k;
            dp[st][end] = INF;
            
            int sum_page = sum[end] - sum[st - 1];
            // 중간 부분으로 나눠서 최솟값 계산 
            for (int mid = st; mid < end; mid++) {
                dp[st][end] = min(dp[st][end],
                                  dp[st][mid] + dp[mid + 1][end] + sum_page);
            }
        }
    }
    
    cout << dp[1][novel] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 0;
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
    
    return 0;
}