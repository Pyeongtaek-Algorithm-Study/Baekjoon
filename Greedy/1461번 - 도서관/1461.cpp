// 1461번: 도서관
#include <iostream>
#include <vector>
#include <algorithm> // for sort(), abs(), max()

using namespace std;

#define endl '\n'

int n = 0, m = 0, MAX = -1; 
vector<int> posi_v, nega_v;
int ans = 0;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp > 0) {
            posi_v.push_back(tmp);
        }
        else {
            nega_v.push_back(-tmp);
        }
        MAX = max(MAX, abs(tmp));
    }
    sort(posi_v.begin(), posi_v.end());
    sort(nega_v.begin(), nega_v.end());
}

void solve() {
    for(int i = posi_v.size() - 1; i >= 0; i-=m) {
        ans += posi_v[i] * 2;
    }
    for(int i = nega_v.size() - 1; i >= 0 ; i-=m) {
        ans += nega_v[i] * 2;
    }
    ans -= MAX;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}