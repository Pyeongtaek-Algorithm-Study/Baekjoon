#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

ll n, k;
vector<ll> len;

void input() {
    cin >> n >> k;
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        len.push_back(a);
    }
}

void solve() {
    ll ans = 0;
    ll st = 1, end = *max_element(len.begin(), len.end());
    
    while(st <= end) {
        ll cnt = 0;
        ll mid = (st + end) / 2;
        
        for(int i = 0; i < n; i++) {
            cnt += len[i] / mid;
        }
        
        if(cnt >= k) {
            st = mid + 1;
            ans = max(ans, mid);
        }
        else end = mid - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    input();
    solve();
    
    return 0;
}