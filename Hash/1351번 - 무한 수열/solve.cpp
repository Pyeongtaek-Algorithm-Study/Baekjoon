#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll N, P, Q;
map<ll, ll> m;

ll A_i(ll num) {
    if (num == 0) return 1;
		// if(m[num]) return m[num]; 으로 대체 가능
    if (m.find(num) != m.end()) return m[num];
    m[num] = A_i(num/P) + A_i(num/Q);
    return m[num];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> P >> Q;
    if ( N == 0 ) {
        cout << "1";
        return 0;
    }
    cout << A_i(N) << '\n';
    
    return 0;
}
