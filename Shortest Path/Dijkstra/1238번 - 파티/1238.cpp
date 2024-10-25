#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define INF 987654321

int n, m, x;
vector<pair<int, int> > v[2][1001];
int min_dis[2][1001];

void input() {
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        v[0][a].push_back({t, b});
        v[1][b].push_back({t, a});
    }
    fill_n(&min_dis[0][0], 2 *1001, INF);
}

void dijkstra(int k) {
    priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > pq;
    min_dis[k][x] = 0;
    
    pq.push({0, x});
    while(!pq.empty()) {
        int dest = pq.top().Y;
        int weight = pq.top().X;
        pq.pop();
        
        if(min_dis[k][dest] < weight) continue;
        
        for(int i = 0; i < v[k][dest].size(); i++) {
            int next = v[k][dest][i].Y;
            int next_weight = v[k][dest][i].X + weight;
            if(min_dis[k][next] > next_weight) {
                min_dis[k][next] = next_weight;
                pq.push({next_weight, next});
            }
        }
    }
}

void solve() {
    int res[1001] = { 0, };
    
    dijkstra(0);
    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        res[i] = min_dis[0][i] + min_dis[1][i];
    }
    
    cout << *max_element(res + 1, res + n + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}