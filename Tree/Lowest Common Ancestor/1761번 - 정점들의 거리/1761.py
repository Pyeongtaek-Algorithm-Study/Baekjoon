import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
edge = list([] for _ in range(n + 1))

# parents, depth, dist
each_val = list([0] * (n + 1) for _ in range(3))
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    edge[a].append([b, c])
    edge[b].append([a, c])

    
def bfs(st):
    vis = [False] * (n + 1)
    
    Q = deque()
    Q.append(st)
    vis[st] = True
    while Q:
        cur = Q.pop()
        
        for nxt, l in edge[cur]:
            if vis[nxt]:
                continue
            each_val[0][nxt] = cur
            each_val[1][nxt] = each_val[1][cur] + 1
            each_val[2][nxt] = each_val[2][cur] + l
            vis[nxt] = True
            Q.append(nxt)
    
def lca(na, nb):
    len_na, len_nb = each_val[2][na], each_val[2][nb]
    
    if each_val[1][na] > each_val[1][nb]:
        na, nb = nb, na
        
    while each_val[1][na] < each_val[1][nb]:
        nb = each_val[0][nb]
        
    while na != nb:
        na = each_val[0][na]
        nb = each_val[0][nb]
    
    return len_na + len_nb - (2 * each_val[2][na])
    
def solve():
    bfs(1)
    
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        print(lca(a, b))

if __name__ == '__main__':
    solve()