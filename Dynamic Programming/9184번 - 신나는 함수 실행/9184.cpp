#include <iostream>

using namespace std;

int a, b, c;
bool chk = false;
int dp[21][21][21] = { 0, };

void input() {
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1) chk = true;
}

int w(int wa, int wb, int wc) {
    if(wa <= 0 || wb <= 0 || wc <= 0) {
        return 1;
    }
    
    if(wa > 20 || wb > 20 || wc > 20) {
        return w(20, 20, 20);
    }
    
    if(dp[wa][wb][wc]) return dp[wa][wb][wc];
    else if(wa < wb && wb < wc) {
        dp[wa][wb][wc] = w(wa, wb, wc-1) + w(wa, wb-1, wc-1) - w(wa, wb-1, wc);
    }
    else {
        dp[wa][wb][wc] = w(wa-1, wb, wc) + w(wa-1, wb-1, wc) + w(wa-1, wb, wc-1) - w(wa-1, wb-1, wc-1);
    }
    
    return dp[wa][wb][wc];
}

void solve() {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        input();
        if(chk) break;
        solve();
    }

    return 0;
}