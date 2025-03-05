import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
board: list = [list(map(int, [i for i in input().rstrip()])) for _ in range(n)]

def bfs() -> int:
    vis = [[[0] * m for _ in range(n)] for _ in range(2)]
    q = deque()
    q.append([0, 0, 0])
    vis[0][0][0] = 1
    
    while q:
        w, x, y = q.popleft()
        
        if x == n - 1 and y == m - 1:
            return vis[w][x][y]
        
        for d in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx: int = x + d[0]
            ny: int = y + d[1]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if board[nx][ny] == 0 and vis[w][nx][ny] == 0:
                vis[w][nx][ny] = vis[w][x][y] + 1
                q.append([w, nx, ny])
            if board[nx][ny] == 1 and w == 0:
                vis[w + 1][nx][ny] = vis[w][x][y] + 1
                q.append([w + 1, nx, ny])
    
    return -1

def solve():
    print(bfs())

if __name__ == '__main__':
    solve()