import sys

input = sys.stdin.readline

LOG = 20
LIM = 100001

n = int(input())
energys = [0] + [int(input()) for _ in range(n)]
path = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    path[a].append([b, c])
    path[b].append([a, c])
parents = [ [0] * (LOG) for _ in range(LIM) ]
table = [ [0] * (LOG) for _ in range(LIM) ]
 
def dfs(curNode, preNode):
    parents[curNode][0] = preNode
    
    for nxtNode, nxtDist in path[curNode]:
        if nxtNode != preNode:
            table[nxtNode][0] = nxtDist
            dfs(nxtNode, curNode)
        
def solve():
    dfs(1, 0)
    
    for j in range(1, LOG):
        for i in range(1, n + 1):
            table[i][j] = table[i][j-1] + table[parents[i][j-1]][j-1]
            parents[i][j] = parents[parents[i][j-1]][j-1]
            
    for i in range(1, n + 1):
        pos, energy = i, energys[i]
        for j in reversed(range(LOG)):
            if parents[pos][j] != 0 and energy >= table[pos][j]:
                energy -= table[pos][j]
                pos = parents[pos][j]
        print(pos)


if __name__ == '__main__':
    solve()