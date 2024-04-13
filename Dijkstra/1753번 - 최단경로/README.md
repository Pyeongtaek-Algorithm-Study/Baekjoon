### 1753번: 최단 경로

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1753)

**문제 조건**
- 가중치 그래프가 존재 *(아래는 입력 변수 정보 및 Dijkstra 설명)*
> V (1 ≤ V ≤ 20,000) : 정점 개수  
> E : 간선 개수  
> u, v, w : 시작 정점, 도착 정점, 시작에서 도착 정점까지 가는 가중치  
> **Dijkstra 설명 블로그** : https://wooono.tistory.com/397

**출력**  
- 시작 정점에서 부터 각 모든 정점(자신 정점 포함)의 최단 경로로 **가중치의 합 최소** 구하기

### 풀이
1. 가중치 그래프를 탐색하기 위해 배열 또는 우선 순위 큐를 사용하지만, 이 문제에서는 `priority_queue` 사용(시간 복잡도 및 V의 최댓값으로 배열 생성 시 메모리 초과) 
2. 우선 순위 큐로 정렬 방식을 가중치를 기준으로 오름차순으로 정렬
3. 시작 정점을 기준으로, 다음 정점에 가장 인접한`(가중치가 낮은)` 정점부터 확인
4. 이를 반복적으로 하며 방문하지 않은 다음 정점들을 최단 경로 값을 구해 `min_arr[]` 저장

### 핵심 코드
<details>
<summary>코드 살펴보기</summary>

```
for(int i=0; i<e; i++) {
        cin >> st_node >> ed_node >> weight;
        // edge 벡터의 각 start_node의 가중치 저장
        edge[st_node].push_back(make_pair(weight, ed_node));
    }
```
- `edge[st_node]` 에 저장할 때 **(weight, ed_node)의 쌍**으로 저장한다. 왜냐하면, `weight`를 기준으로 오름차순을 하기 위함임. (왼쪽부터 가장 높은 기준)

```
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
```

- `min_arr[start_value]` : 처음 시작 노드인 `K`에서 `K`로 가는 비용은 0
- `int arrive_weight = -pq.top().first;` : 우선 순위 큐는 기본 정렬 방식이 내림 차순이다. 따라서, 가중치가 가장 낮은 것부터 상단에 위치하기 위해 오름차순으로 정렬하기 위해 음수를 곱한다. 이후에 가중치 값을 활용할 땐 다시 음수를 곱해 양수로 이용한다.    
> ex. 원본 가중치 : 24 12 53일 때  
> 우선 순위 큐 저장 : -12 -24 -53  
> 가중치 값 활용 : 12 24 53

- `int next_arrive_weight = arrive_weight + edge[arrive_node][i].first;` : 현재 정점까지의 가중치와 다음 정점의 가중치의 합을 의미한다.  
이후에, `min_arr[next] > next_arrive_weight` 이면 **다음 정점에 도달까지의 최단 거리가 min_arr에 저장된 다음 정점까지의 최단 거리보다 짧은 것**이므로 `min_arr[next]` 에 최단 거리를 갱신한다. 
- 다음 정점을 큐에 저장하여 큐가 비워질 때 까지 반복한다.

</details>
