#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

void input() {
    cin >> n >> k;
}

void solve() {
    int ans = 0;
    
    while(1) {
        // ans는 추가 물병 개수
        int tmp = n + ans;
        int cnt = 0;
        
        // tmp의 값을 2진수로 1의 개수를 파악
        while(tmp) {
            if(tmp & 1) cnt++;
            tmp >>= 1;
        }
        
        if(cnt <= k) break;
        ans++;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}