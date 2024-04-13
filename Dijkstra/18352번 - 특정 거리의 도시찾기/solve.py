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
