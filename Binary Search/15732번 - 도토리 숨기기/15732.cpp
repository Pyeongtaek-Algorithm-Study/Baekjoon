#include <iostream>
#include <vector>

using namespace std;

#define lim 1000001
#define ll long long

ll n, k, d;
vector<vector<int> > rule;

void input() {
    cin >> n >> k >> d;
    for(int i = 0, a, b, c; i < k; i++) {
        cin >> a >> b >> c;
        rule.push_back({a, b, c});
    }
}

void solve() {
    int l = 0, r = n;
    int mid = 0, res = 0;
    
    while(l <= r) {
        ll sum = 0;
        mid = (l + r) / 2;
        
        for(int i = 0; i < k; i++) {
            int last = min(mid, rule[i][1]);
            if(last >= rule[i][0]) sum += (last - rule[i][0]) / rule[i][2] + 1;
        }
        
        if(sum >= d) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}