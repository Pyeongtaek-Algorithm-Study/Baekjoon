#include <iostream>

using namespace std;

int n, m;
int scale[31] = { 0, };
int find_weight[8] = { 0, };
// 무게 추 i 개를 이용해서 j 의 무게를 만들 수 있는가?
bool dp[31][(500 * 30) + 1] = { false, };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> scale[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> find_weight[i];
    }
}

void dfs(int cnt, int w) {
    if(cnt > n || dp[cnt][w]) return;
    dp[cnt][w] = true;
    
    dfs(cnt + 1, w + scale[cnt]); // 무게 추 합산(오른쪽 추가)
    dfs(cnt + 1, abs(w - scale[cnt])); // 무게 추 차이(왼쪽 추가)
    dfs(cnt + 1, w); // 무게 추 사용 안함
}

void solve() {
    dfs(0, 0);
    
    for(int i = 0; i < m; i++) {
        if(find_weight[i] > 15000) cout << "N" << ' ';
        else if(dp[n][find_weight[i]]) cout << "Y" << ' ';
        else cout << "N" << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}