import sys


def dfs(graph, v, visited):
    visited.append(v)
    for i in graph[v]:
        if i not in visited:
            dfs(graph, i, visited)

    return visited


a=int(sys.stdin.readline())
b=int(sys.stdin.readline())
graph=[[] for i in range(a+1)]
for _ in range(b):
    x,y=map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)

visited=[]
print(len(dfs(graph,1,visited))-1)
