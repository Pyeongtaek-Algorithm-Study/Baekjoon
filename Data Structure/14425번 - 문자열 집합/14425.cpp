#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<string> set_str;
vector<string> ins_str;

void input() {
    cin >> n >> m;
    string st;
    
    for(int i = 0; i < n; i++) {
        cin >> st;
        set_str.insert(st);
    }
    for(int i = 0; i < m; i++) {
        cin >> st;
        ins_str.push_back(st);
    }
}

void solve() {
    int ans = 0;
    
    for(string &in : ins_str) {
        if(set_str.find(in) != set_str.end()) ans++;
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