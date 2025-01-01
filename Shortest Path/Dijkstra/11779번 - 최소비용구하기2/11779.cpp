#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1e9

int n, m, st, ed;
vector<pair<int, int> > path[1001];
vector<int> save[1001];
int weight[1001];

void input() {
    cin >> n >> m;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
    }
    
    cin >> st >> ed;
}

void solve() {
    fill_n(&weight[0], 1001, MAX);
    weight[st] = 0;
    save[st].push_back(st);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, st});
    
    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(weight[cur_node] < w) continue;
        
        for(int i = 0; i < path[cur_node].size(); i++) {
            int next_node = path[cur_node][i].first;
            int next_weight = w + path[cur_node][i].second;
            
            if(weight[next_node] > next_weight) {
                weight[next_node] = next_weight;
                pq.push({next_weight, next_node});
                save[next_node] = save[cur_node];
                save[next_node].push_back(next_node);
            }
            
        }
    }

    cout << weight[ed] <<'\n' << save[ed].size() << '\n';
    for(int i = 0; i < save[ed].size(); i++) {
        cout << save[ed][i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}