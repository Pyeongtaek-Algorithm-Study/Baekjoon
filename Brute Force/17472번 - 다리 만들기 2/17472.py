import sys

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
vis = [[False] * m for _ in range(n)]
edges = []
parents = list(range(n * m))


def dfs(x, y, num):
    global vis
    vis[x][y] = True
    arr[x][y] = num
    
    for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < n and 0 <= ny < m:
            if not vis[nx][ny] and arr[nx][ny] == 1:
                dfs(nx, ny, num)

def bridge(x, y, land):
    for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
        w = 0
        nx = x
        ny = y
        while(1):
            nx += dx
            ny += dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m: 
                break
            new_island = arr[nx][ny]
            if new_island != 0:
                if new_island != land and w >= 2:
                    edges.append([w, land, new_island])
                break
            w += 1

def Find(x):
    if x != parents[x]:
        parents[x] = Find(parents[x])
    return parents[x]
    
def Union(a, b):
    a = Find(a)
    b = Find(b)
    if a != b:
        parents[b] = a

def solve():
    island_cnt = 1
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1 and not vis[i][j]:
                dfs(i, j, island_cnt)
                island_cnt += 1
    
    for i in range(n):
        for j in range(m):
            if arr[i][j] != 0:
                bridge(i, j, arr[i][j])
    
    edges.sort()
    edge_cnt = 0
    min_weight = 0
    chk = False
    for edge in edges:
        if Find(edge[1]) == Find(edge[2]):
            continue
        
        Union(edge[1], edge[2])
        min_weight += edge[0]
        edge_cnt += 1
        
        if edge_cnt == island_cnt - 2:
            chk = True
            break
    
    print(min_weight if chk else -1)


if __name__ == '__main__':
    solve()