// 1062번: 가르침
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;
int alpha = 0;
int result = 0;

void input() {
    cin >> n >> k;

    alpha |= (1 << ('a' - 'a'));
    alpha |= (1 << ('c' - 'a'));
    alpha |= (1 << ('i' - 'a'));
    alpha |= (1 << ('n' - 'a'));
    alpha |= (1 << ('t' - 'a'));
    vector<int> tmp(n, 0);

    for(int i = 0; i < n; i++) {
        string s = "";
        cin >> s;
        for(int j = 0; j < s.length(); j++) 
            tmp[i] |= (1 << (s[j] - 'a'));
    }
    
    v = tmp;
}

void dfs(int alpha, int level, int idx) {
    if(!level) {
        int cnt = 0;

        for(int i = 0; i < n; i++)
            if((alpha & v[i]) == v[i]) cnt++;

        result = max(result, cnt);
    }
    else {
        int x = 0;

        for(int i = idx; i < 26; i++) {
            x = 1 << i;
            if((alpha & (x))) continue;
            alpha |= x;
            dfs(alpha, level - 1, i);
            alpha ^= x;
        }
    }
}

void solve() {
    if(k < 5) {
        cout << 0 << "\n";
        exit(0);
    }
    k -= 5;
    dfs(alpha, k, 0);
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}