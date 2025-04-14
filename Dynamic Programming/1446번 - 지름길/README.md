### 1446번: 지름길

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1446)
2. **도움 블로그** : https://velog.io/@soonsoo3595/PS-%EB%B0%B1%EC%A4%80-1446%EB%B2%88%EC%8B%A4%EB%B2%84-1-%EC%A7%80%EB%A6%84%EA%B8%B8

**문제 조건**
- 세준이는 학교에 가기 위해서 고속도로를 타고 가는데, 이 고속도로는 커브가 많아서 운전이 힘듬
- 어느날 이 학교로 가는 고속도로에 **지름길**이 있는 것을 확인했고, 지름길은 일반통행이며 역주행할 수 없음

**출력**  
- 세준이가 지름길을 통해 **운전해야 하는 거리의 최솟값**을 출력

### 풀이
1. 문제 풀이 설명

### 핵심 코드

<details>
<summary>코드 보기</summary>

```py
def dijkstra():
    # 최단 거리 초기 설정
    weights = [INF] * (d + 1)
    
    # 각 경로의 초기 설정
    edges = [[] for _ in range(d + 1)]
    for i in range(d):
        edges[i].append([i + 1, 1]) 
        
    # 입력받은 지름길 추가
    for li in short:
        if li[1] > d:
            continue
        edges[li[0]].append([li[1], li[2]])
    
    # dijkstra 알고리즘    
    pq = []
    heapq.heappush(pq, [0, 0])
    weights[0] = 0
    
    while pq:
        src, cost = heapq.heappop(pq)
        
        if weights[src] < cost:
            continue
        
        for edge in edges[src]:
            if weights[edge[0]] > weights[src] + edge[1]:
                weights[edge[0]] = weights[src] + edge[1]
                heapq.heappush(pq, edge)
        
    return weights[d]
```
- dijkstra 알고리즘 풀이법으로, `weights`는 `d` 거리까지의 최소 거리들을 기록
- `edges`는 각 거리에서 다음 거리를 갈 때의 비용들을 저장할 리스트로 기본적으로 현재 위치에서 다음 위치로는 비용이 1이 드는 것들을 저장
- 다음은 `edges`에 지름길을 추가하여 지름길의 도착 위치가 `d` 거리 이내 인 것들만 추가
- 현재 `src`에서 다음으로 갈 수 있는 경로들인 `edges[]`에서 도착 위치인 `edge[0]`의 위치가 (현재 위치 값 + `edge[1]`)과 비교하여 더 작은 값일 경우 값을 갱신
- 위 과정들을 반복하면은 `weights[]`의 각 거리에는 최소로 갈 수 있는 거리들이 저장됌으로 `d` 위치일 때의 값을 출력

```py
def solve():
    sorted_short = sorted(short, key = lambda x : x[1])
    dp = list(range(d + 1))
    
    for li in sorted_short:
        src, des, cost = li
        if des > d:
            continue
        
        dp[des] = min(dp[des], dp[src] + cost)
        
        for j in range(des + 1, d + 1):
            dp[j] = min(dp[j], dp[j - 1] + 1)
    
    print(dijkstra())
    # print(dp[d])
```
- DP 풀이법으로, 입력받은 지름길을 도착지점을 기준으로 오름차순으로 정렬한 `sortrd_short`
- 1부터 도착 지점까지의 최소 거리를 값을 저장할 `dp`, 지름길의 출발, 도착, 거리를 나타낼 `src`, `des`, `cost`
- `des`가 최종 도착할 d보다 크면은 해당 지름길을 사용하지 못하므로 건너뜀
- `dp[]`에 도착 지점의 현재 값과 (출발 지점의 거리 + 지름길 거리) 를 비교하여 더 짧은 것을 저장
- 도착 지점의 값이 수정되면은 해당 도착 지점 이후부터 `d`까지의 값들을 수정(중간 위치에서 더 짧아졌으므로, 뒷 부분까지 전부 갱신)
</details>

### 후기
- DP 문제라는 것은 캐치했지만, 해내지 못했음
- 도착 위치의 값이 갱신된 이후 그 **뒷부분들**도 더 작게 갱신들을 해야 한다는 것을 빼먹음