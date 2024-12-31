#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<int> seq;

void input() {
    cin >> n >> s;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        seq.push_back(tmp);
    }
}

bool compare(int a, int b) {
    return a < b;
}

void solve() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> chk(i, 1);
        for(int j = 0; j < n - i; j++) chk.push_back(0);
        sort(chk.begin(), chk.end(), compare);
        
        do {
            int total = 0;
            for(int k = 0; k < n; k++) if(chk[k]) total += seq[k];
            if(s == total) ans++;
        } while(next_permutation(chk.begin(), chk.end()));
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