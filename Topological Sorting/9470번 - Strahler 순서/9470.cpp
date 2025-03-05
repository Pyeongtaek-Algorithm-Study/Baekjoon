// 9470번: Strahler 순서
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int k, m, p;
vector<int> river[MAX];
int degree[MAX] = { 0, };
int strahler[2][MAX] = { 0, };

void input() {
    for(int i = 0; i < MAX; i++) river[i].clear();
    fill_n(&degree[0], MAX, 0);
    fill_n(&strahler[0][0], 2* MAX, 0);
    
    cin >> k >> m >> p;
    for(int i = 0, a, b; i < p; i++) {
        cin >> a >> b;
        river[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    queue<int> Q;
    int ans = 0;
    
    for(int i = 1; i <= m; i++) {
        if(!degree[i]) {
            Q.push(i);
            strahler[0][i] = 1;
        }
    }
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        ans = max(ans, strahler[0][cur]);
        
        for(int i = 0; i < river[cur].size(); i++) {
            int ncur = river[cur][i];
            if(strahler[0][ncur] < strahler[0][cur]) {
                strahler[0][ncur] = strahler[0][cur];
                strahler[1][ncur] = 0;
            }
            else if(strahler[0][ncur] == strahler[0][cur] && !strahler[1][ncur]) {
                strahler[0][ncur]++;
                strahler[1][ncur] = 1;    
            }
            
            if(--degree[ncur] == 0) Q.push(ncur);
        }
    }
    
    cout << k << ' ' << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
    
    return 0;
}