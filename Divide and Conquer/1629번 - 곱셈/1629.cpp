#include <iostream>

using namespace std;

#define ll long long
ll a, b, c;

void input() {
    cin >> a >> b >> c;
}

ll divide(ll n) {
    if(n == 0) return 1;
    if(n == 1) return a % c;
    
    ll tmp = divide(n/2) % c;
    if(n % 2) {
        return tmp * tmp % c * a % c;
    }
    else {
        return tmp * tmp % c;
    }
}

int divide2(ll m, ll n, int mod) {
    int r = 1;
    while (n != 0) {
        if (n & 1) r = (r * m) % mod;
        m = (m * m) % mod;
        n >>= 1;
    }
    return r;
}

void solve() {
    cout << divide(b) << "\n";
    // cout << divide2(a, b, c) << "\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}