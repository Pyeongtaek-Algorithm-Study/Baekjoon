# 11779번 최소비용구하기2
***
### 문제 해설
- n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.<br>
A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.<br>
그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하면 된다. 항상 시작점에서 도착점으로의 경로가 존재한다. <br>
***
### 문제 링크

- <https://www.acmicpc.net/problem/11779>
***
### 문제 풀이
- 우선 순위 큐와 다익스트라 알고리즘 활용하면 최소비용을 구할 수 있다.<br>
우선 각 출발 도시별 도착도시 번호와 버스 비용이 주어질때 graph[출발도시].append(도착도시,비용)을 해준다.<br>
이제 출발점의 도시번호와 도착점의 도시번호가 주어진다. <br>
출발점은 거리가 0이니, 우선 순위 큐에 (출발점,비용)를 넣어준다.<br>
이제 큐에 요소가 없을때까지 반복문을 돌려준다.<br>
조건문으로 비용[출발도시]가 큐에서 나온 출발도시의 비용보다 작다면 continue를 이용해 밑에 코드를 실행시키지 않는다.<br>
이제 출발도시가 가는 도착도시들을 반복문으로 탐색해준다.<br>
출발도시의 비용+도착도시 까지 비용이 cost[도착도시]보다 작다면 값을 업데이트 해주고 큐에 넣어준다.<br>
경로를 출력하는 방법은 v = [[] for _ in range(n + 1)]를 초기화해주고,<br>
우선 v[start].append(start) 해준다.<br>
그런다음 반복문에서 최소 비용으로 바껴질때, v[도착 도시 번호]=v[해당 도시 번호].copy 하여 값을 복사한다.<br>
리스트를 복사해줄땐 리스트=리스트 이런식으로 해주면 안된다.<br>
그런다음, 자신의 도시 번호를 추가해주면 경로가 된다.<br>

### 코드
<pre>
  <code>
    import heapq
import sys
def dijkstra(start, end):
    cost[start] = 0
    q = []
    heapq.heappush(q, (start, 0))
    v[start].append(start)

    while q:
        now, cos = heapq.heappop(q)
        # print(now, cos)
        if cost[now] < cos:
            continue
        for i in graph[now]:
            if cost[i[0]] > cos + i[1]:
                cost[i[0]] = cos + i[1]
                heapq.heappush(q, (i[0], cos + i[1]))
                v[i[0]]=v[now].copy()
                # print(v[now])
                v[i[0]].append(i[0])
    print(cost[end])
    print(len(v[end]))
    print(' '.join(map(str,v[end])))

    return (cost)


input = sys.stdin.readline
INF = 1e8
n = int(input())
m = int(input())
cost = [INF] * (n + 1)
graph = [[] for _ in range(n + 1)]
v = [[] for _ in range(n + 1)]
for i in range(m):
    st, ed, co = map(int, input().split())
    graph[st].append((ed, co))

start, end = map(int, input().split())

dijkstra(start, end)

  </code>
</pre>
