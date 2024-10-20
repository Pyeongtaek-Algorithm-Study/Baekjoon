#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define INF 987654321

int n, m;
int city[201][201];
int possible[201];
int plan[2001];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> city[i][j];
        }
    }
    for(int i = 1; i <= m; i++) {
        cin >> plan[i];
    }
}

bool dijkstra(int st, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    fill(&possible[0], &possible[n+1], INF);
    
    pq.push({0, st});
    possible[st] = 0;
    
    while(!pq.empty()) {
        int dest = pq.top().Y;
        int weight = pq.top().X;
        pq.pop();
        
        if(dest == end) {
            return true;
        }
        
        if(possible[dest] < weight) continue;
        
        for(int i = 1; i <= n; i++) {
            if(city[dest][i] == 0) continue;
            int next_dest = i;
            int next_weight = city[dest][i] + weight;
            
            if(possible[next_dest] > next_weight) {
                possible[next_dest] = next_weight;
                pq.push({next_weight, next_dest});
            }
        }
    }
    return false;
}

void solve() {
    int idx = 1;
    while(idx < m) {
        if(!dijkstra(plan[idx], plan[idx+1])) break;
        idx++;
    }
    cout << (idx == m ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}