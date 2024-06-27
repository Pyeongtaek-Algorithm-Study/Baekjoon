// 3079번: 입국심사
#include <iostream>

using namespace std;

#define ll long long

int n, m;
int arr[100001];
ll MAX = 0;
ll ans = 0;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(MAX < arr[i]) MAX = arr[i];
    }
}

void solve() {
    ll st = 0;
    ll end = MAX * m;
    
    while(st <= end) {
        ll sum = 0;
        ll mid = (st + end) / 2;
        for(int i = 0; i < n; i++) {
            sum += (mid / arr[i]);
            // overflow 발생
            if(sum > m) break;
        }
        if(sum >= m) {
            end = mid - 1;
            ans = mid;   
        }
        else st = mid + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}