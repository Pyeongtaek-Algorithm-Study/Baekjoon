### 1504번: 특정한 최단 경로

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1504)
2. **도움 블로그** : 

**문제 조건**
- 방향성이 없는 그래프이며, 1번 정점에서 N번 정점까지 최단 거리로 이동하고자 함
- 두 조건을 만족하는 **특정한 최단 경로**를 구하고자 함
    - 임의로 주어진 두 정점이 1번 정점에서 N번 정점까지 가는데 반드시 거쳐야 함
    - 한번 방문했던 정점 또는 한번 이동했던 간선도 다시 거치거나 이동해도 상관 없음

**출력**  
- 1번 정점에서 N번 정점까지 가는데 임의의 두 정점을 **반드시 거치는 최단 경로의 길이**를 출력
- 만일, 그러한 경로가 없을 시엔 -1을 출력

### 풀이
1. 두 정점(v1, v2)이 주어질 때 도착 정점까지의 크게 경우의 수는 2개  
_시작 - v1 - v2 - 도착, 시작 - v2 - v1 - 도착_
2. 최단 경로의 케이스 값은 시작부터 도착까지 **각각의 정점을 도착할 때 해당 최단 경로**끼리 합하면은 최종적인 최단 경로 값
3. _ex. 시작 - v1 - v2 - 도착일 경우, dijkstra(시작 - v1), dijkstra(v1 - v2), dijkstra(v2 - 도착)이 각각 3개의 최단 경로 합이라는 뜻_
4. 두 경우의 수를 각각 구해서 값을 비교하여 최솟값을 출력
5. 만일 정답인 최솟값이 `INF` 보다 크면은 도착 정점까지 경로가 없는 것이므로 -1을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    int case_1 = 0, case_2 = 0;
    
    dijkstra(1);
    case_1 += min_val[v1];
    case_2 += min_val[v2];
    
    dijkstra(v1);
    case_1 += min_val[v2];
    case_2 += min_val[n];
    
    dijkstra(v2);
    case_1 += min_val[n];
    case_2 += min_val[v1];
    
    int ans = min(case_1, case_2);
    cout << (ans >= INF ? -1 : ans) << '\n';
}
```
- `case_1`은 시작-v1-v2-도착의 최단 경로 값, `case_2`은 시작-v2-v1-도착의 최단 경로 값
- `dijkstra(1)`로 시작 정점으로 각 정점의 최단 경로 값을 구해서 `case_1`, `case_2`에 각각 `v1`, `v2`까지의 최단 값을 더함
- `dijkstra(v1)`로 v1 정점에서 각 정점의 최단 경로 값을 구해서 `case_1`, `case_2`에 각각 `v2`, `n`번 정점 까지의 최단 값을 더함
- `dijkstra(v2)`로 v2 정점에서 각 정점의 최단 경로 값을 구해서 `case_1`, `case_2`에 각각 `n`, `v1`번 정점 까지의 최단 값을 더함
- 최종적으로 `case_1`의 값은 "시작-v1-v2-도착" 의 경로의 최소 경로 값, `case_2`의 값은 "시작-v2-v1-도착" 의 경로의 최소 경로 값
- `ans` 값에 `case_1`, `case_2`의 최소값을 비교하여 저장한 후 `INF` 값보다 큰지 비교
- `INF` 값보다 같거나 크면은 **중간에 경로가 없어서 INF 값을 사전에 더한 것**이므로 -1을 출력하고 아니면은 `ans` 값인 최단 경로를 출력
</details>

### 후기
- 처음에 `INF`의 값을 1e9로 설정했더니 case 값들이 오버플로우가 나서 음수나는 경우도 존재했어서 1억으로 설정
- 뒤늦게 생각해보면, 최악의 경우 매우 큰 값인 `INF`들 끼리 더할 수 있으니 애초에 _int_ 형 말고 _long long_ 으로 했어도 괜찮을 것 같음.