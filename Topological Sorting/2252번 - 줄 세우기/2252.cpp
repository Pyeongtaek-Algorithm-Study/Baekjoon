// 2252번: 줄 세우기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > v;
vector<int> degree;

void input() {
    cin >> n >> m;
    v.resize(n + 1);
    degree.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!degree[i]) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        for(auto next : v[now]) {
            degree[next]--;
            if(!degree[next]) q.push(next);
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