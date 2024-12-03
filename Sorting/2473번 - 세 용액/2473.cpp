#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
vector<ll> sol;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sol.push_back(tmp);
    }
}

void solve() {
    sort(sol.begin(), sol.end());
    
    // long long 최댓값이 1e18
    ll comp = 1e18; 
    vector<ll> elements;
    
    for(int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            ll sum = sol[i] + sol[l] + sol[r];
            
            if(comp > abs(sum)) {
                comp = abs(sum);
                elements = { sol[i], sol[l], sol[r] };
            }
            
            if(sum < 0) l++;
            else r--;
        }
    }
    
    for(auto &it : elements) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}