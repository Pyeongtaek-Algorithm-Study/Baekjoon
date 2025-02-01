#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101
#define INF 9876

int n, m;
vector<int> person[MAX], group, delegate;
bool vis[MAX];
int floyd[MAX][MAX];

void input() {
    cin >> n >> m;
    fill_n(&floyd[0][0], MAX * MAX, INF);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        person[a].push_back(b);
        person[b].push_back(a);
        floyd[a][b] = 1;
        floyd[b][a] = 1;
    }
}

void dfs(int node) {
    vis[node] = true;
    group.push_back(node);
    for(int i = 0; i < person[node].size(); i++) {
        int next_node = person[node][i];
        if(!vis[next_node]) dfs(next_node);
    }
}

int head(vector<int> people) {
    int dist_val = INF;
    int headpoint = -1;
    
    for(int i = 0; i < people.size(); i++) {
        int cur = people[i];
        int max_val = -1;
        for(int j = 1; j <= n; j++) {
            if(floyd[cur][j] == INF) continue;
            max_val = max(max_val, floyd[cur][j]);
        }
        
        // new head
        if(dist_val > max_val) {
            headpoint = cur;
            dist_val = max_val;
        }
    }
    return headpoint;
}

void solve() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) floyd[i][j] = 0;
                else floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            group.clear();
            dfs(i);
            int headpoint = head(group);
            if(headpoint != -1) delegate.push_back(headpoint);
        }
    }
    
    sort(delegate.begin(), delegate.end());
    cout << delegate.size() << '\n';
    for(auto &it : delegate) cout << it << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}