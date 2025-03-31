import sys
from collections import deque

def case():
    n, k = map(int, input().split())
    time = [0] + list(map(int, input().split()))
    res_time = time[:]
    graph = [[] for _ in range(n + 1)]
    indegree = [0] * (n + 1)

    for _ in range(k):
        x, y = map(int, input().split())
        graph[x].append(y)
        indegree[y] += 1

    w = int(input())

    Q = deque(i for i in range(1, n + 1) if indegree[i] == 0)

    while Q:
        cur = Q.popleft()
        for nxt in graph[cur]:
            res_time[nxt] = max(res_time[nxt], res_time[cur] + time[nxt])
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                Q.append(nxt)

    print(res_time[w])

def solve():
    t = int(input())
    for _ in range(t):
        case()
    
if __name__ == '__main__':
    solve()