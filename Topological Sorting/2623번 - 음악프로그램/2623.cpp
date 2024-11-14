#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int n, m;
vector<int> v[MAX];
int degree[MAX];

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int cnt, a, b;
        cin >> cnt >> a;
        while(--cnt) {
            cin >> b;
            v[a].push_back(b);
            degree[b]++;
            a = b;
        }
    }
}

void solve() {
    queue<int> q;
    vector<int> ans;
    
    for(int i = 1; i <= n; i++)
        if(degree[i] == 0) q.push(i);
        
    while(!q.empty()) {
        int now = q.front(); q.pop();
        ans.push_back(now);
        for(int i = 0; i < v[now].size(); i++) {
            int nxt = v[now][i];
            if(--degree[nxt] == 0) q.push(nxt);
        }
    }
    
    if(ans.size() == n) {
        for(int &it : ans) cout << it << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}