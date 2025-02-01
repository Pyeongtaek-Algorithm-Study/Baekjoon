import sys
from collections import deque

input = sys.stdin.readline

MAX = 101
INF = 10**2

n = int(input())
m = int(input())
relation = list([] for _ in range(n + 1))
vis = [False] * (n + 1)
floyd = [[INF] * (n + 1) for _ in range(n + 1)]
delegate = []
for _ in range(m):
    a, b = map(int, input().split())
    relation[a].append(b)
    relation[b].append(a)
    floyd[a][b] = floyd[b][a] = 1

def bfs(node, arr):
    Q = deque()
    Q.append(node)
    vis[node] = True

    while Q:
        cur = Q.pop()
        arr.append(cur)
        for nextNode in relation[cur]:
            if not vis[nextNode]:
                Q.append(nextNode)
                vis[nextNode] = True

    return arr
    
def groupPoint(group):
    distVal = INF
    curPoint = -1
    
    for person in group:
        maxVal = -1
        for i in range(n + 1):
            if floyd[person][i] == INF:
                continue
            maxVal = max(maxVal, floyd[person][i])
        
        if distVal > maxVal:
            distVal = maxVal
            curPoint = person
    
    return curPoint

def solve():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if i == j:
                    floyd[i][j] = 0
                else:
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])
    
    for i in range(1, n + 1):
        if not vis[i]:
            group = bfs(i, [])
            delegate.append(groupPoint(group))
    
    sortedDelegate = sorted(delegate)
    sortedDelegate = [len(sortedDelegate)] + sortedDelegate
    print('\n'.join(map(str, sortedDelegate)))

if __name__ == '__main__':
    solve()