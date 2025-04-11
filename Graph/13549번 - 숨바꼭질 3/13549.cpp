#include <iostream>
#include <deque>

using namespace std;

#define X first
#define Y second

int n, k;
int vis[100001];

void input() {
    cin >> n >> k;
    fill_n(&vis[0], 100001, -1);
}

void solve() {
    deque<int> dq;
    dq.push_front(n);
    vis[n] = 0;
    
    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        
        for(int nxt : {cur * 2, cur - 1, cur + 1}) {
            if(nxt < 0 || nxt >= 100001 || vis[nxt] != -1) continue;
            
            if(nxt == cur * 2) {
                vis[nxt] = vis[cur];
                dq.push_front(nxt);
            }
            else {
                vis[nxt] = vis[cur] + 1;
                dq.push_back(nxt);
            }
        }
    }
    
    cout << vis[k] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}