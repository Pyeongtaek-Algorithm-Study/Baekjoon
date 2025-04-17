#include <iostream>

using namespace std;

int n, k;
int arr[200001] = { 0, };
int cnt[100001] = { 0, };

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    int len = 0, ans = 0;
    
    for(int i = 0, j = 0; i < n; i++) {
        int cur = arr[i];
        cnt[cur]++;
        len++;
        
        while(cnt[cur] > k) {
            cnt[arr[j++]]--;
            len--;
        }
        
        ans = max(ans, len);
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