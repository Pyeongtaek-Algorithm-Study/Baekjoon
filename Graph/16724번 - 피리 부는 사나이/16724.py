import sys

input = sys.stdin.readline

n, m = map(int, input().split())
board = [input().rstrip() for _ in range(n)]
vis = [[0] * m for _ in range(n)]
ans = 1

def dfs(x, y):
    global ans
    vis[x][y] = ans
    nx, ny = x, y
    if board[x][y] == 'D':
        nx += 1
    elif board[x][y] == 'U':
        nx -= 1
    elif board[x][y] == 'R':
        ny += 1
    else:
        ny -= 1
    
    if vis[nx][ny] == 0:
        dfs(nx, ny)
    elif vis[nx][ny] != 0 and vis[nx][ny] == ans:
        ans += 1
    vis[x][y] = vis[nx][ny]

def solve():
    for i in range(n):
        for j in range(m):
            if vis[i][j] == 0:
                dfs(i, j)
    print(ans - 1)

if __name__ == '__main__':
    solve()