#include <iostream>

using namespace std;

int l, n;
int ant[100001] = { 0, };

void input() {
    cin >> l >> n;
    for(int i = 0; i < n; i++) {
        cin >> ant[i];
    }
}

void solve() {
    int ans_min = 0, ans_max = 0;
    
    while(n--) {
        int sht = min(ant[n], l - ant[n]), lon = max(ant[n], l - ant[n]);
        ans_min = max(ans_min, sht);
        ans_max = max(ans_max, lon);
    }
    
    cout << ans_min << ' ' << ans_max << '\n';
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