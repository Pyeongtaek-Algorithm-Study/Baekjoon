#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string s, t;

void input() {
    cin >> s >> t;
}

void solve() {
    for(int i = t.length(); i > s.length(); i--) {
        char tmp = t[t.length() - 1];
        t = t.substr(0, t.length() - 1);
        if(tmp == 'B') {
            reverse(t.begin(), t.end());
        }
    }
    if(s == t) cout << "1" << "\n";
    else cout << "0" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}