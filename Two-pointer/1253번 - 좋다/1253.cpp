// 1253번 - 좋다
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = 0;
vector<int> v;

void solve() {
    for(int i = 0; i < n; i++) {
        int l = 0;
        int r = n - 2;
        vector<int> cp_v = v;
        cp_v.erase(cp_v.begin() + i);
        
        while(l < r) {
            int total = cp_v[l] + cp_v[r];
            if(v[i] == total) {
                res++;
                break;
            }
            else if(total < v[i]) l++;
            else if(total > v[i]) r--;
        }
    }
    cout << res << '\n';
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}