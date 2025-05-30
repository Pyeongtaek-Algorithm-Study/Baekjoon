#include <iostream>
#include <queue>

using namespace std;

#define LIM 1000001
#define INF 1e9

int f, s, g, u, d;
int vis[LIM];

void input() {
    cin >> f >> s >> g >> u >> d;
}

void solve() {
    fill_n(&vis[0], LIM, INF);
    queue<int> Q;
    Q.push(s);
    vis[s] = 0;
    
    while(!Q.empty()) {
        int cur_f = Q.front(); Q.pop();
        int nxt_f = cur_f + u;
        int pre_f = cur_f - d;
        
        if(nxt_f <= f && vis[nxt_f] > vis[cur_f] + 1) {
            vis[nxt_f] = vis[cur_f] + 1;
            Q.push(nxt_f); 
        }
        
        if(pre_f > 0 && vis[pre_f] > vis[cur_f] + 1) {
            vis[pre_f] = vis[cur_f] + 1;
            Q.push(pre_f);
        }
    }
    
    (vis[g] != INF) ? cout << vis[g] : cout << "use the stairs";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}