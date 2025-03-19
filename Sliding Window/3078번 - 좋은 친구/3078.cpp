#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<string> stu;
int cnt[21] = { 0, };
queue<int> Q[21];

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        stu.push_back(str);
    }
}

void solve() {
    long long ans = 0;
    
    // solution 1
    for(int i = 0; i <= k; i++) cnt[stu[i].length()]++;
    
    for(int i = 0; i < n; i++) {
        cnt[stu[i].length()]--;
        ans += cnt[stu[i].length()];
        if(i + k + 1 < n) cnt[stu[i + k + 1].length()]++;
    }
    
    // solution 2
    // for(int i = 0; i < n; i++) {
    //     int len = stu[i].length();
    //     while(!Q[len].empty() && (i - Q[len].front() > k)) Q[len].pop();
    //     ans += Q[len].size();
    //     Q[len].push(i);
    // }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}