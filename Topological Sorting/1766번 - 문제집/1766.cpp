// 1766번: 문제집
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[32001];
int degree[32001] = { 0, };

void input() {
    cin >> n >> m;
    for(int i = 0, a , b; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++)
        if(!degree[i]) pq.push(i);
    
    while(!pq.empty()) {
        int now = pq.top(); pq.pop();
        cout << now << ' ';
        for(int i = 0; i < v[now].size(); i++) {
            if(--degree[v[now][i]] == 0) pq.push(v[now][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}