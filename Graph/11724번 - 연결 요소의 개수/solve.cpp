#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
    visited[x] = true;
    for(int i = 0; i < graph[x].size(); i++) {
        int cur = graph[x][i];
        if(!visited[cur]) dfs(cur);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프이기 때문에 양쪽으로 입력
    }
    int cnt  = 0;
    for(int i = 1; i < N+1; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}