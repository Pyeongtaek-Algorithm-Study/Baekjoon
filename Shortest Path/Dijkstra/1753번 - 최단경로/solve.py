import heapq

v, e = map(int, input().split())
k = int(input())
graph = [[] for _ in range(v + 1)]
INF = 1e8
distance = [INF] * (v + 1)
for i in range(e):
    start, end, w = map(int, input().split())
    graph[start].append((w,end))


def dijkstra(k):
    distance[k] = 0
    q = []
    heapq.heappush(q, (0,k))
    while q:
        dist,now = heapq.heappop(q)
        if dist > distance[now]:
            continue

        for a, b in graph[now]:
            if dist+a<distance[b]:
                distance[b]=dist+a
                heapq.heappush(q,(dist+a,b))

    return distance


lst = dijkstra(k)
for i in lst[1:]:
    if i == 1e8:
        print("INF")
    else:
        print(i)
