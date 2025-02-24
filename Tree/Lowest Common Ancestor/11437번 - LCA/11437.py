import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
edge = list([] for _ in range(n + 1))
parents = [0] * (n + 1)
depth = [0] * (n + 1)
vis = [False] * (n + 1)
for _ in range(n - 1):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)
    

def bfs(node):
    dq = deque()
    dq.append(node)
    
    while dq:
        node = dq.popleft()
        vis[node] = True
        
        for next_node in edge[node]:
            if vis[next_node]:
                continue
            parents[next_node] = node
            depth[next_node] = depth[node] + 1
            dq.append(next_node)
        

def lca(node_a, node_b):
    if depth[node_a] > depth[node_b]:
        node_a, node_b = node_b, node_a
    
    while depth[node_a] != depth[node_b]:
        node_b = parents[node_b]

    while node_a != node_b:
        node_a = parents[node_a]
        node_b = parents[node_b]
        
    return node_a
        
def solve():
    bfs(1)
    
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        print(lca(a, b))
    

if __name__ == '__main__':
    solve()