#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LIM 20001
#define RED 2
#define BLUE 3

int tc;
int v, e;
vector<int> edges[LIM];

int color[LIM] = { 0, };

void all_clear() {
    fill_n(&color[0], LIM, 0);
    for(int i = 1; i < LIM; i++) {
        edges[i].clear();
    }
}

void input() {
    cin >> v >> e;
    
    all_clear();
    
    for(int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

bool bfs(int st) {
    queue<int> Q;
    Q.push(st);
    color[st] = RED;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int nxt_color = (color[cur] == RED ? BLUE : RED);
        
        for(int i = 0; i < edges[cur].size(); i++) {
            int nxt = edges[cur][i];
            if(!color[nxt]) {
                color[nxt] = nxt_color;
                Q.push(nxt);
            } else if(color[cur] == color[nxt]) {
                return false;
            }
        }
    }
    
    return true;
}

void solve() {
    bool ans = true;
    for(int i = 1; i <= v; i++) {
        if(!color[i]) ans = bfs(i);
        // 만일, 이분그래프가 아닐 경우, 바로 종료
        if(!ans) break;
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
    
    return 0;
}