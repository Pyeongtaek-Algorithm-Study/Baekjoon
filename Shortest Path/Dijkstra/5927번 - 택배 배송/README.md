### 5927번: 택배 배송

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/5927)

**문제 조건**
- 농부는 지도를 가지고 있으며, `N` 개의 헛간과, `M`의 양방향 길, 각 길에는 `C` 마리의 소가 있다.
- 농부 현서는 농부 찬홍이에게 배달하는데 길에서 만나는 소들만큼 여물을 줘야한다.
- **현서는 1 헛간에 있고 찬홍은 N 헛간에 있을 때 여물의 최소만 줘서 배달**하고자 한다.

**출력**  
- 1 헛간에서 N 헛간까지의 최소 여물이 될 수 있는 길로 갈 때의 개수를 구하기

### 풀이
1. 노드가 1, 2, ..., n인 헛간들이며, 입력 값 `a_i`, `b_i`는 두 노드를 가리치며, `c_i`는 두 노드 사이의 가중치를 의미한다.
2. `a_i`, `b_i` 노드를 입력받을 때, 방향성이 없는 그래프이므로, `vector edge`에 값을 저장할 때 `a_i` -> `b_i`와 `b_i` -> `a_i` 의 가는 방향들을 모두 저장한다.
3. `Dijkstra` 알고리즘으로 1번 노드부터 N번 노드까지의 최소 가중치들을 구하고, 마지막 N번 노드의 가중치값을 출력한다.

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
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
```
- `input()` 함수에서 노드 간의 가중치를 저장할 때 `a_i` -> `b_i` 방향과 `b_i`에서 `a_i` 방향 모두 저장한다.  
_당연히 두 노드 사이의 가중치는 그대로 이므로 방향만 반대고 가중치는 그대로인 것을 edge에 추가한다_
- `priority_queue<weight, dest_node>`를 통해 오름차순으로 정렬하도록 하고, 1번 노드에서 시작하도록 한다.  
_pq에 시작노드를 추가할 때, 자기 자신의 가중치는 0_
- `dest` 노드까지 가는 가중치가 현재 저장된 `min_arr`의 값보다 크면은 의미가 없으므로 건너간다.  
_최소비용을 구하고 싶으므로 이미 해당 노드로 가는 최소비용보다 큰 것이므로_
- `dest` 노드에서 다른 노드로 갈 수 있는 개수인 `edge[dest].size()`만큼 반복
- 다음 노드까지의 가중치(비용)는 현재 노드까지의 가중치(weight)와 다음 노드까지의 비용의 합이다.
- `min_arr`에 저장된 가중치보다 `next_weight` 가 더 작다면 1번 노드부터 해당 노드까지 가는 최소비용이므로 갱신
- 다음 방문 노드를 `pq`에 추가하여 반복

</details>