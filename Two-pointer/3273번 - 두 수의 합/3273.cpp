#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int nums[1000001];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> x;
}

void solve() {
    int ans = 0;
    
    sort(nums, nums + n);
    
    int l = 0, r = n - 1;
    while(l < r) {
        int sum = nums[l] + nums[r];
        if(sum == x) ans++;
        
        if(sum <= x) l++;
        else r--;
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