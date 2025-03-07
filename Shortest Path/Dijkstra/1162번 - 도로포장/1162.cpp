#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e15
#define ll long long
#define X first
#define Y second

int n, m, k;
vector<pair<int, int>> edges[10001];
ll dp[21][10001];

void input() {
    cin >> n >> m >> k;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
}

ll dijkstra() {
    fill_n(&dp[0][0], 21 * 10001, INF);
    priority_queue<pair<pair<ll, int>, int> > pq;
    pq.push({{0, 1}, 0});
    dp[0][1] = 0;

    while (!pq.empty()) {
        ll cost = -pq.top().X.X;
        int node = pq.top().X.Y;
        int cnt = pq.top().Y;
        pq.pop();
        
        if (dp[cnt][node] < cost) continue;

        for (auto &edge : edges[node]) {
            int nxt_node = edge.X;
            ll nxt_cost = cost + edge.Y;

            if (dp[cnt][nxt_node] > nxt_cost) {
                dp[cnt][nxt_node] = nxt_cost;
                pq.push({{-nxt_cost, nxt_node}, cnt});
            }

            if (dp[cnt + 1][nxt_node] > cost && cnt + 1 <= k) {
                dp[cnt + 1][nxt_node] = cost;
                pq.push({{-cost, nxt_node}, cnt + 1});
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[i][n]);
    return ans;
}

void solve() {
    cout << dijkstra() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}
