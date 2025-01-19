#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 801
#define INF 100000000

int n, e, v1, v2;
vector<pair<int, int> > v[MAX];
int min_val[MAX];

void input() {
    cin >> n >> e;
    for(int i = 0, a, b, c; i < e; i++) {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    cin >> v1 >> v2;
}

void dijkstra(int st) {
    fill_n(&min_val[0], MAX, INF);
    
    priority_queue<pair<int, int> > pq;
    pq.push({0, st});
    min_val[st] = 0;
    
    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        
        if(min_val[node] < weight) continue;
        
        for(int i = 0; i < v[node].size(); i++) {
            int next_node = v[node][i].second;
            int next_weight = v[node][i].first + weight;
            
            if(min_val[next_node] > next_weight) {
                min_val[next_node] = next_weight;
                pq.push({-next_weight, next_node});
            }
        }
    }
}

void solve() {
    int case_1 = 0, case_2 = 0;
    
    dijkstra(1);
    case_1 += min_val[v1];
    case_2 += min_val[v2];
    
    dijkstra(v1);
    case_1 += min_val[v2];
    case_2 += min_val[n];
    
    dijkstra(v2);
    case_1 += min_val[n];
    case_2 += min_val[v1];
    
    int ans = min(case_1, case_2);
    cout << (ans >= INF ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}