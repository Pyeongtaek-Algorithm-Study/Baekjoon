특정거리의 도시찾기
=============
- 문제 해설
  
각 도시가 있고, 도로가 있다.

도시에서 도시로 가는 도로를 이용하려고 할때, 최단 도로를 구해야한다.

최단 도로들 중 특정 거리인 도로가 나오면 그 도시를 return 해주면 된다.

- 문제 링크
<https://www.acmicpc.net/problem/18352>

- 문제 풀이
  
각 도시의 갯수(노드 갯수), 각 도로 갯수(간선 갯수), 시작노드, 원하는 최단 거리를 입력받는다.

INF=1e8로 초기화해준다.

distance = [INF] * (N + 1), graph = [[] for _ in range(N + 1)] 로 초기화해준다.

N+1인 이유는 리스트의 인덱스를 노드의 번호로 맞추기 위함이다.

예로, distance[4]=INF,graph[4]=[]  

각 가중치(도로의 길이)는 모두 1이므로

graph[도시].append(이동할 도시,1) 해주었다.

이제 우선 순위 큐에다 거리와 시작 노드를 넣어준다. 시작 노드의거리는 0이니 (0,x)를 우선순위 큐에다 넣어준다.

이제 큐에 요소가 없을때까지 반복문을 돌려준다.

큐에 pop하여 거리와 노드값을 구해준다.

만약 이미 distance[노드]가 pop한 거리보다 작다면 최단 거리로만

계산을 해야하므로 continue하여 밑에 반복문을 실행시키지 않게 한다.

반복문으로 pop한 노드로부터 도착하는 노드들을 탐색해준다.

가중치와 도로를 구해 현재 거리+가중치가 distance[도착 도시] 보다 작다면

값을 갱신해주고, 큐에 거리와 그 도시 번호를 넣어준다.

우선 순위 큐이므로, 다음에 pop하는 도시는 경로가 가장 최단인 도로가 pop될 것이다.

이제 그 노드를 똑같이 반복해주면 된다.

그럼 각 도시별 최단 도로의 길이가 리스트 형태로 return된다.

이제 그 리스트를 반복문하여 전체적으로 탐색해준다.

특정 거리인 k인 수가 나온다면 그 거리의 도시, 즉 그 값에 인덱스를 출력해주면 된다.

- 코드
<pre>
  <code>
    import heapq

N, M, K, X = map(int, input().split())
graph = [[] for _ in range(N + 1)]
INF = 1e8
distance = [INF] * (N + 1)

for i in range(M):
    A, B = map(int, input().split())
    graph[A].append((B, 1))


def dijkstra(graph, start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for i in graph[now]:
            if dist + i[1] < distance[i[0]]:
                distance[i[0]] = dist + i[1]
                heapq.heappush(q, (dist + i[1], i[0]))


dijkstra(graph, X)
c=0
m=-1
for i in distance:
    c=c+1
    if i==K:
        m=0
        print(c-1)

if m==-1:
    print(-1)
  </code>
</pre>
