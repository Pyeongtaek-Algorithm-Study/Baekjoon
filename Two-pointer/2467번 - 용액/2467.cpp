// 2467번: 용액
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n = 0;
vector<ll> v;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve() {
    int l = 0;
    int r = n - 1;
    
    ll ans_sum = abs(v[l] + v[r]);
    ll ans_l = v[l];
    ll ans_r = v[r];
    
    while(l < r) {
        ll sum = v[l] + v[r];
        
        if(abs(sum) < ans_sum) {
            ans_sum = abs(sum);
            ans_l = v[l];
            ans_r = v[r];
        }
        
        if(sum < 0) l++;
        else r--;
    }
    cout << ans_l << " " << ans_r << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}