// 1722번: 순열의 순서
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
long long k;
vector<int> v;

void solve() {
    int chk[n + 1] = {0, };
    long long factorial[n + 1];
    factorial[0] = factorial[1] = 1;
    for(int i = 2; i <= n; i++) factorial[i] = i * factorial[i - 1];
    
    if(l == 1) {
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= n; j++) {
                if(chk[j-1]) continue;
                if(k > factorial[i]) k -= factorial[i];
                else {
                    chk[j-1] = 1;
                    cout << j << " ";
                    break;
                }
            }
        }
    }
    else {
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < v[i - 1]; j++) {
                if(chk[j]) continue;
                ans += factorial[n - i];
            }
            chk[v[i - 1]] = 1;
        }
        cout << ans;
    }
}

void input() {
    cin >> n >> l;
    
    if(l == 1) {
        cin >> k;
    }
    else {
        int tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }    
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}