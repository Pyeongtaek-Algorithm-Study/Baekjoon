### 14938번: 서강그라운드

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14938)
2. **도움 블로그** : 

**문제 조건**
- 서강그라운드는 여러 지역 중 하나의 지역에 낙하산을 타고 낙하하여, 그 지역에 떨어져 있는 아이템들을 이용해 서바이벌 하는 게임
- 예은이는 서강그라운드를 즐겨하지만 1등을 하지 못하며 이는 자기가 떨어지는 지역에 있는 아이템 운이 없는 것이라 생각
- 각 지역에 아이템이 몇 개 있는지 알려주는 프로그램을 개발했지만, 어디로 떨어져야 자신의 **수색 범위 내에서 가장 많은 아이템**을 얻을 수 있는지 알 수 없음
- 각 지역은 다른 지역과 연결되어 있고, 양방향 통행이 가능하며, 예은이는 수색 범위 내에 있는 **모든 아이템**을 습득 가능

**출력**  
- 예은이가 얻을 수 있는 **최대 아이템 개수**를 출력

### 풀이
1. 예은이의 수색 범위가 있을 때, 어느 지역에서 시작하느냐에 따라서 얻을 수 있는 아이템 개수들이 달라짐
2. 따라서, 시작할 수 있는 지역의 개수는 n개 100 이하임으로, 시작 위치의 모든 경우에서 _Dijkstra_ 로 각 도시의 최소 거리들을 확인
3. 위 과정에서 얻을 도시의 최소 거리가 수색 범위 내인지 확인하여 가능한 경우 해당 도시의 아이템들을 합산
4. 위 과정들을 통해 각 도시에서 시작할 때 얻을 수 있는 아이템들을 비교하여 **최대로 얻을 수 있는 개수**를 구한 후, 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
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
```
- 시작 도시인 `st`값을 입력받고 일반적인 _Dijkstra_ 알고리즘을 진행
- `dist[]` 에는 `st` 도시에서 각 도시까지의 최소 거리들이 저장
- 각 도시까지의 거리인 `dist[]`로  수색 범위인 `m` 이하 인지 확인
- 예은이가 수색할 수 있는 도시라면은 해당 도시에 있는 아이템 개수를 `item_cnt`에 합산후, 반환

```cpp
void solve() {
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dijkstra(i));
    }
    
    cout << ans << '\n';
}
```
- 최대로 얻을 수 있는 아이템 개수인 `ans`에 0을 저장
- `dijkstra()`를 통해서 `i`번 도시에서 시작할 떄 얻을 수 있는 아이템 개수와 `ans`와 최댓값 비교  
- 모든 도시에서의 경우를 다 확인 후, 최대로 얻을 수 있는 아이템 개수가 저장된 `ans` 값을 출력
</details>

### 후기
- 