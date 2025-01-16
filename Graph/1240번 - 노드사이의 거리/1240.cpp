#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int, int> > v[1001];
vector<pair<int, int> > out;
int vis[1001];

void input() {
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        out.push_back({a, b});
    }
}

void dfs(int st, int end, int weight) {
    vis[st] = 1;
    
    if(st == end) {
        cout << weight << '\n';
        return;
    }
    
    for(int i = 0; i < v[st].size(); i++) {
        int n_st = v[st][i].X;
        int n_weight = v[st][i].Y + weight;
        
        if(!vis[n_st]) dfs(n_st, end, n_weight);
    }
}

void bfs(int st, int end) {
    queue<pair<int, int> > Q;
    Q.push({st, 0});
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X] = 1;
        
        if(cur.X == end) {
            cout << cur.Y << '\n';
            break;
        }
        
        for(int i = 0; i < v[cur.X].size(); i++) {
            int n_st = v[cur.X][i].X;
            int n_weight = v[cur.X][i].Y + cur.Y;
            if(!vis[n_st]) Q.push({n_st, n_weight});
        }
    }
}

void solve() {
    for(auto &it : out) {
        dfs(it.X, it.Y, 0);
        // bfs(it.X, it.Y);
        fill_n(&vis[0], 1001, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;   
}