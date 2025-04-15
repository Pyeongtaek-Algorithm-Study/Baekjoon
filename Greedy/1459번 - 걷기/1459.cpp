#include <iostream>

using namespace std;

#define LIM 100001

long long x, y, w, s;

void input() {
    cin >> x >> y >> w >> s;
}

void solve() {
    long long ans = 0;
    
    long long cross = min(x, y);
    int time_1 = min(w * 2, s);
    ans += (cross * time_1);
    
    long long diff = abs(x - y);
    int time_2 = min(w, s);
    
    if(diff % 2 == 0) ans += (diff * time_2);
    else ans += ((diff - 1) * time_2 + w);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}