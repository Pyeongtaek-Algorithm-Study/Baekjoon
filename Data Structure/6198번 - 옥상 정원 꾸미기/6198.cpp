#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void solve() {
    stack<int> roof;
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        while(!roof.empty() && roof.top() <= v[i]) {
            roof.pop();
        }
        ans += roof.size();
        roof.push(v[i]);
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