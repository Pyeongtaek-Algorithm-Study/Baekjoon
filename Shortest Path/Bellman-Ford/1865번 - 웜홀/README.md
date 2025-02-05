### 1865번: 웜홀

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1865)
2. **도움 블로그** : 

**문제 조건**
- 월드나라는 N개의 지점이 있고, 지점들 사이에 M개의 도로와 W개의 웜홀이 있음
- 도로는 방향이 없으나, 웜홀은 방향이 존재하며 도로는 일정 시간을 소모하지만 웜홀은 시간을 반대로 거슬러 감
- 한 지점에서 출발하여 시간 여행을 시작하여 다시 출발위치로 돌아왔을 때, 출발한 시각보다 도착 시각이 더 과거일 수 있는지 궁금해함


**출력**  
- 출발한 후, 다시 출발 위치로 돌아왔을 때의 시간이 더 과거가 가능한지의 여부를 출력하며 가능하먼 "YES", 불가능하면 "NO"를 출력

### 풀이
1. 시작지점의 최단 시간을 0으로 초기화
2. 나머지 도착 지점들은 매우 큰 값인 `INF` 값으로 초기화
3. _Bellman-Ford_ 알고리즘으로 각 경로를 `n`번씩 반복
4. 위 과정을 반복하여 각 지점마다의 최단 경로 값 저장
5. 각 경로들을 한번씩 반복하여 기존 도착 값보다 더 값이 작아진다면은 **음수 사이클이 존재하는 것**이므로, 출발 시각보다 도착 시각이 더 과거가 됨.
6. 음수 사이클이 존재시에, "YES"를 출력, 없을 시에는 "NO"를 출력


### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
string bellmanford(int start) {
    dist[start] = 0;
    
    for(int i = 0; i < n; i++) {
        for(auto &edge : edges) {
            int cur_node = edge[0], next_node = edge[1], edge_cost = edge[2];
            
            if(dist[cur_node] + edge_cost < dist[next_node]) {
                dist[next_node] = dist[cur_node] + edge_cost;
            }
        }
    }
    
    for(auto &edge : edges) {
        int cur_node = edge[0], next_node = edge[1], edge_cost = edge[2];
        
        if(dist[cur_node] + edge_cost < dist[next_node]) {
            return "YES";
        }
    }
    
    return "NO";
}
```
- `start` 지점의 값을 시작지점으로 0으로 초기화
- `edges`에는 도로와 웜홀의 경로들이 저장되어있으며, 경로 탐색하는 횟수를 `n`번 반복함
- 다음 도착 시간인`dist[next_node]` 이 현재 시간`dist[cur_node]` + 소모 시간`edge_cost`의 합보다 크면은 더 짧은 시간에 도착 지점에 갈 수 있으므로 값을 갱신
- 마지막으로 웜홀과 같은 경로에 **과거로 돌아가는 음수하여 음수 사이클이 있을 수 있으므로** 각 경로들을 1번씩 추가 실행
- 만일, 이때 더 시간을 짧게 하는 경로가 있다면은 이는 **음수의 사이클이 존재하는 것**이므로 이 과정을 무한히 하면 무한대값이 나옴
- 그러면은 결론적으로 다시 출발 지점까지 과거로 갈 순 있다는 뜻이므로 "YES"를 출력
- 경로를 다시 한번씩 탐색했지만, 값이 갱신되는 것이 없으면은 각각의 최단 시간의 변화가 없는 것이므로 음수의 사이클이 존재하지 않으므로 "NO" 출력
</details>

### 후기
- _Bellman-Ford_ 알고리즘을 해볼 수 있는 좋은 문제라 생각됨
- 