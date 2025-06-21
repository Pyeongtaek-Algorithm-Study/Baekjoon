// 22865번 : 가장 먼 곳
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int n, m;
vector<int> friends;
vector<pair<int, int> > roads[500001];
int min_dist[3][100001] = { 0, };

void input() {
    cin >> n;
    friends.resize(3);
    for(int i = 0; i < 3; i++) {
        cin >> friends[i];
    }
    cin >> m;
    for(int i = 0, d, e, l; i < m; i++) {
        cin >> d >> e >> l;
        roads[d].push_back({e, l});
        roads[e].push_back({d, l});
    }
}

void dijkstra(int idx, int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>  > pq;
    pq.push({0, st});
    min_dist[idx][st] = 0;
    
    while(!pq.empty()) {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(min_dist[idx][cur] < dist) continue;
        
        for(int i = 0; i < roads[cur].size(); i++) {
            int nxt_dist = dist + roads[cur][i].second;
            int nxt = roads[cur][i].first;
            
            if(min_dist[idx][nxt] > nxt_dist) {
                min_dist[idx][nxt] = nxt_dist;
                pq.push({nxt_dist, nxt});
            }
        }
    }
}

void solve() {
    int dist = 0;
    int ans = -1;
    
    fill_n(&min_dist[0][0], 3 * 100001, INF);
    
    // 친구들의 위치에서 각 거리들을 저장
    for(int i = 0; i < 3; i++) {
        dijkstra(i, friends[i]);
    }
    
    for(int i = 1; i <= n; i++) {
        // 친구들의 위치는 건너뜀
        if(i == friends[0] || i == friends[1] || i == friends[2]) continue;
        
        // 친구들의 위치가 아닌 것에서 가장 가까이 갈 수 있는 친구 거리
        int from_away = min(min_dist[0][i], min(min_dist[1][i], min_dist[2][i]));
        
        // 기존 거리보다 더 멀리 존재하는 것이라면 갱신
        if(dist < from_away) {
            dist = from_away;
            ans = i;
        }
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