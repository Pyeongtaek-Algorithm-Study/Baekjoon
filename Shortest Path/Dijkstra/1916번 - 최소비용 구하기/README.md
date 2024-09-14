### 1916번: 최소비용 구하기

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1916)

**문제 조건**
- `N`개의 도시에 한 도시에서 다른 도시로 도착하는 `M`개의 버스가 존재
- 버스의 정보를 `M`개 제공하여 출발 도시 -> 도착 도시까지의 버스 비용 주어줌.

**출력**  
- A 도시에서 B도시 까지 가는 **최소 비용** 출력

### 풀이
1. 기본적인 **Dijkstra 알고리즘 문제**
2. `priority_queue`를 활용하여 거리를 기준으로 내림차순 정렬
3. 기본적으로 내림차순으로 정렬되므로 `weight`에 해당하는 거리비용에 -를 곱하여서 오름차순으로 정렬되도록 함.  
_(값을 활용할 때는 다시 -를 곱해서 양수로 이용)_
4. 출발 도시에서 도착 도시까지의 비용이 0 ~ 100000 사이의 정수이므로 `min_arr[]`를 통해 출발 도시에서 각 도시까지의 비용을 최소로 갱신함.
5. 어떤 해당 도시로 가는 최소비용이 `weight`에 저장된 값보다 작다면은 해당 버스를 굳이 사용할 필요가 없으므로 `continue`로 건너감.  
_※ 안그러면 해당 경로들을 다 파악해야 하여 시간 초과가 발생_
6. `priority_queue`를 통해 다음 도시로 가는 비용이 `min_arr`에 저장된 값보다 작은 경우 새로운 최소비용이므로 갱신
7. `priority_queue`가 완전히 비어질 때까지 반복

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
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
```
- `priority_queue`는 기본적으로 내림차순 정렬(`pair`의 `first` 부분은 거리비용)
- 오름차순으로 값을 활용하기 위해 -를 곱하여 `pq`에 저장
- 현 도시 `dest`에서 다음 도시로 가는 비용인 `next_weight`가 `min_arr`에 저장된 비용보다 작은 경우 `next` 도시로 가는 최소비용이므로 새롭게 갱신
- `priority_queue`에 `-next_weigth`로 값을 저장하여 오름차순으로 하도록 진행
- `priority_queue`가 완전히 비어질 떄 까지 반복하여 해당 갈 수 있는 도시들의 최소 비용을 찾기
</details>