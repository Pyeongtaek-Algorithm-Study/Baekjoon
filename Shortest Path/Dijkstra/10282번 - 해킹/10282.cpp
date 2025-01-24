// 10282번: 해킹
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10001
#define X first
#define Y second

int t, n, d, c;
vector<pair<int, int> > com[MAX];
int min_sec[MAX];

void input() {
    cin >> n >> d >> c;
    
    // com 각 초기화
    for(int i = 0; i <= n; i++) {
        com[i].clear();
    }
    for(int i = 0, a, b, s; i < d; i++) {
        cin >> a >> b >> s;
        com[b].push_back({a, s});
    }
    for(int i = 1; i <= n; i++) {
        min_sec[i] = 1e9;
    }
}

void dijkstra(int st) {
    priority_queue<pair<int, int> > pq;
    min_sec[st] = 0;
    pq.push({0, st});
    
    while(!pq.empty()) {
        int weight = -pq.top().X;
        int node = pq.top().Y;
        pq.pop();
        
        if(min_sec[node] < weight) continue;
        
        for(int i = 0; i < com[node].size(); i++) {
            int next_node = com[node][i].X;
            int next_weight = com[node][i].Y + weight;
            
            if(min_sec[next_node] > next_weight) {
                min_sec[next_node] = next_weight;
                pq.push({-next_weight, next_node});
            }
        }
    }
}

void solve() {
    dijkstra(c);
    
    int cnt = 0, sec = 0;
    for(int i = 1; i <= n; i++) {
        if(min_sec[i] != 1e9) {
            cnt++;
            sec = max(sec, min_sec[i]);
        }
    }
    cout << cnt << ' ' << sec << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    
    return 0;
}