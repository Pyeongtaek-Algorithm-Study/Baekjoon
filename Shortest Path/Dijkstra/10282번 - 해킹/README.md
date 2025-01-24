### 10282번: 해킹

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/10282)
2. **도움 블로그** : https://ongveloper.tistory.com/182

**문제 조건**
- 해커 yum3이 네트워크 시설의 한 컴퓨터를 해킹
- 임의의 컴퓨터를 의존하는 컴퓨터들은 점차 일정 시간뒤에 해킹이 전염
- a가 b 컴퓨터를 의존하면 b가 감염되면 a도 감염하고, 만일 b가 a를 의존하지 않으면은 a가 감염되도 b는 안전

**출력**  
- 각 테스트 케이스마다 총 감염되는 **컴퓨터 수**, 마지막 컴퓨터가 감염되기까지 걸리는 **최소 시간**을 공백을 두고 출력

### 풀이
1. 임의의 한 컴퓨터에 시작하여 각각의 감염되는 최소 시간을 파악하기 위해 _Dijkstra_ 알고리즘을 사용
2. `min_sec[]`에 각 컴퓨터 번호에 큰 값을 지정
3. `dijkstra()`을 사용하여 시작 컴퓨터에서 각 컴퓨터까지 걸리는 최소 시간을 계단하여 `min_sec[]`에 저장
4. 각 최소 시간을 파악한 후에 `min_sec[]`에서 각 컴퓨터마다 초기값이 아닌것을 확인
5. 초기값이 아닌 것은 해킹에 **전염된 컴퓨터**이고, 마지막 컴퓨터까지 걸리는 최소 시간은 전염된 컴퓨터들 중에서 가장 **큰 값**
6. 각 테스트 케이스마다 출력해야 하므로 위 값을 출력한 후에, 다시 **초기화**해야 하므로 입력받은 데이터들을 `clear()` 함.

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void dijkstra(int st) {
    priority_queue<pair<int, int> > pq;
    min_sec[st] = 0;
    pq.push({0, st});
    
    while(!pq.empty()) {
        int weight = -pq.top().X;
        int node = pq.top().Y;
        pq.pop();
        
        if(min_sec[node] < weight) continue;
        
        for(int i = 0; i < com[node].size(); i++) {
            int next_node = com[node][i].X;
            int next_weight = com[node][i].Y + weight;
            
            if(min_sec[next_node] > next_weight) {
                min_sec[next_node] = next_weight;
                pq.push({-next_weight, next_node});
            }
        }
    }
}
```
- 일반적인 Dijkstra 알고리즘
- 오름차순 정렬을 위해 `weight`값에 음수로 설정


```cpp
void solve() {
    dijkstra(c);
    
    int cnt = 0, sec = 0;
    for(int i = 1; i <= n; i++) {
        if(min_sec[i] != 1e9) {
            cnt++;
            sec = max(sec, min_sec[i]);
        }
    }
    cout << cnt << ' ' << sec << '\n';
}
```
- `c`번 컴퓨터부터 `dijkstra()`을 시작하여 각 컴퓨터에 도달할 수 있는 최소 시간들을 계산
- 위 계산이 완료되면은 `min_sec[]`에 각 컴퓨터에 도달할 수 있는 최소 시간이 저장되며, 만일 도달하지 못하는 컴퓨터는 `1e9`값이 그대로 저장
- `1e9` 값이 아닌 컴퓨터들은 `c`번에서 시간한 컴퓨터에서 해킹에 **전염된 컴퓨터**이고, 최종적으로 걸린 최소 시간은 전염된 컴퓨터들 중에서 가장 **큰 값**
- 위에서 구한 전염된 컴퓨터 수 및 걸린 시각을 공백을 두고 출력
</details>

### 후기
- 자꾸 25% 틀려서 확인해보니 이전에 입력받은 데이터들을 초기화하지 않아서 발생한 문제