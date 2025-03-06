#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INF 1e9

int n, m, r;
int items[101] = { 0, };
vector<pair<int, int> > edges[101];
int dist[101] = { 0, };

void input() {
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) 
        cin >> items[i];
    for(int i = 0, a, b, c; i < r; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
}

int dijkstra(int st) {
    int item_cnt = 0;
    fill_n(&dist[0], 101, INF);
    dist[st] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, st});
    
    while(!pq.empty()) {
        int weight = -pq.top().X;
        int node = pq.top().Y;
        pq.pop();
        
        if(dist[node] < weight) continue;
        
        for(int i = 0; i < edges[node].size(); i++) {
            int nxt_node = edges[node][i].X;
            int nxt_weight = edges[node][i].Y + weight;
            
            if(dist[nxt_node] > nxt_weight) {
                dist[nxt_node] = nxt_weight;
                pq.push({-nxt_weight, nxt_node});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] <= m) item_cnt += items[i];
    }
    
    return item_cnt;
}

void solve() {
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dijkstra(i));
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}