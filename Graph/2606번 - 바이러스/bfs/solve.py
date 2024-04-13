from collections import deque
import sys
def bfs(v, graph, visited):
    q = deque([v])
    while q:
        n = q.popleft()
        for i in graph[n]:
            if visited[i] == 0:
                visited[i] = 1
                q.append(i)
    return sum(visited) - 1

n = int(input())
s = int(input())
visited = [0] * (n + 1)
graph = [[] for i in range(n + 1)]

for i in range(s):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
print(bfs(1, graph, visited))
