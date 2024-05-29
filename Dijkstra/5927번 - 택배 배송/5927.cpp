// 5927번: 택배 배송
#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <cstring>

using namespace std;

#define X first
#define Y second
#define MAX 50001
#define INF 987654321

int min_arr[MAX];
vector<pair<int, int>> edge[MAX];

int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a_i, b_i, c_i;
        cin >> a_i >> b_i >> c_i;
        edge[a_i].push_back({c_i, b_i});
        edge[b_i].push_back({c_i, a_i});
    }
}

void solution(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, st));
    
    while(!pq.empty()) {
        int dest = pq.top().Y;
        int weight = pq.top().X;
        pq.pop();
        if(min_arr[dest] < weight) continue;
        for(int i = 0; i < edge[dest].size(); i++) {
            int next = edge[dest][i].Y;
            int next_weight = edge[dest][i].X + weight;
            if(min_arr[next] > next_weight) {
                min_arr[next] = next_weight;
                pq.push({next_weight, next});
            }
        }
    }
    cout << min_arr[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    for(int i = 0; i <= n; i++) {
        min_arr[i] = 987654321;
    }
    solution(1);
    
    return 0;
}