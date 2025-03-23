import sys
from collections import deque

n, m = map(int, input().split())
guid = [input().rstrip() for _ in range(n)]
ans = 0

def bfs(st_w, st_x, st_y):
    global ans
    
    vis = [[False] * m for _ in range(n)]
    q = deque()
    q.append([st_w, st_x, st_y])
    vis[st_x][st_y] = True
    
    while q:
        w, x, y = q.popleft()
        
        if ans < w:
            ans = w
        
        for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx, ny = x + dx, y + dy
            
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if guid[nx][ny] == 'W' or vis[nx][ny]:
                continue
            vis[nx][ny] = True
            q.append([w + 1, nx, ny])

def solve():
    for i in range(n):
        for j in range(m):
            if guid[i][j] == 'L':
                bfs(0, i, j)
    
    print(ans)

if __name__ == '__main__':
    solve()