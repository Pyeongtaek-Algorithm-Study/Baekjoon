#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define MAX_V 20001
#define MAX_E 300001

int min_arr[MAX_V];

vector<pair<int, int> > edge[MAX_E];

// start_value == K
void dijkstra(int start_value) {
    min_arr[start_value] = 0;
    
    priority_queue<pair<int, int> > pq;
    
    // 우선순위 큐에서 시작노드와 같은 위치의 비용을 0으로 삽입
    pq.push(make_pair(0, start_value));
    
    while(!pq.empty()) {
        int arrive_node = pq.top().second;
        
        int arrive_weight = -pq.top().first;
        
        pq.pop();
        
        // 현재 저장된 노드(min_arr)의 최소 비용보다 도착 노드의 비용이 더 클 때   
        if(min_arr[arrive_node] < arrive_weight) continue;
        
        for(int i=0;i<edge[arrive_node].size(); i++) {
            // 현재 노드와 i번째로 인접한 노드
            int next = edge[arrive_node][i].second;
            
            int next_arrive_weight = arrive_weight + edge[arrive_node][i].first;
            
            if(min_arr[next] > next_arrive_weight) {
                min_arr[next] = next_arrive_weight;
                
                pq.push(make_pair(-next_arrive_weight, next));
                
            }
            
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int v, e, K;
    cin >> v >> e;
    
    cin >> K;
    
    for(int i=1; i<v+1; i++) {
        min_arr[i] = INF;
    }
    
    int st_node, ed_node, weight;
    for(int i=0; i<e; i++) {
        cin >> st_node >> ed_node >> weight;
        // edge 벡터의 각 start_node의 가중치 저장
        edge[st_node].push_back(make_pair(weight, ed_node));
    }
    
    // 시작 값
    dijkstra(K);
    
    for(int i=1;i<v+1;i++) {
        if(min_arr[i]==INF) cout << "INF" << ' ';
        else cout << min_arr[i] << ' ';
    }
    
    return 0;
}
