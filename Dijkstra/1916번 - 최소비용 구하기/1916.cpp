#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second 
#define MAX 1001
#define INF 987654321

int n, m;
int ans_st, ans_des;
int min_arr[MAX];
vector<pair<int, int> > v[100001];

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        vector<int> tmp;
        int s, d, w;
        cin >> s >> d >> w;
        v[s].push_back({d, w});
    }
    fill_n(min_arr, MAX, INF);
    cin >> ans_st >> ans_des;
}

void dijkstra(int st) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    min_arr[st] = 0;
    
    while(!pq.empty()) {
        int dest = pq.top().Y;
        int weight = -pq.top().X;
        pq.pop();
        
        if(min_arr[dest] < weight) continue;
        
        for(int i = 0; i < v[dest].size(); i++) {
            int next = v[dest][i].X;
            int next_weight = v[dest][i].Y + weight;
            if(min_arr[next] > next_weight) {
                min_arr[next] = next_weight;
                pq.push({-next_weight, next});
            }
        }
    }
}

void solve() {
    dijkstra(ans_st);
    cout << min_arr[ans_des];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}