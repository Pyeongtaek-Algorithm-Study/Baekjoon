#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<int> seq;
int ans = 0;

void input() {
    cin >> n >> s;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        seq.push_back(tmp);
    }
}

void back(int idx, vector<int> v) {
    int sum = 0;
    for(int &it : v) sum += it;
    
    if(sum == s && v.size() > 0) ans++;
    
    for(int i = idx; i < n; i++) {
        v.push_back(seq[i]);
        back(i+1, v);
        v.pop_back();
    }
}

void solve() {
    back(0, {});
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}