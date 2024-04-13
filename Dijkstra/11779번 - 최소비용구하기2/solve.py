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

