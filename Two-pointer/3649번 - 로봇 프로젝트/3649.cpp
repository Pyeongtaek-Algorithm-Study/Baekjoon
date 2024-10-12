#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> lego;

void input() {
    lego.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> lego[i];
    }
    sort(lego.begin(), lego.end());
}

void solve() {
    int st = 0;
    int en = lego.size() - 1;
    t *= 10000000;
    while(st < en) {
        if(lego[st] + lego[en] == t) {
            break;
        }
        else if(lego[st] + lego[en] > t) en--;
        else st++;
    }
    if(st < en) cout << "yes " << lego[st] << ' '<< lego[en] << '\n';
    else cout << "danger" << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> t >> n) {
        input();
        solve();
    }
    
    return 0;
}