#include <iostream>

using namespace std;

#define LIM 20001

int n, k;
string str;

void input() {
    cin >> n >> k;
    cin >> str;
}

void solve() {
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        if(str[i] != 'P') continue;

        for(int j = i - k; j <= i + k; j++) {
            if((0 <= j && j < n) && str[j] == 'H') {
                str[j] = '-';
                ans++;
                break;
            }
        }
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