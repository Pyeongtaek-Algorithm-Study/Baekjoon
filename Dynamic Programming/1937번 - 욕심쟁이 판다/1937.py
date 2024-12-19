import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
forest = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

def dfs(x, y):
    if dp[x][y]:
        return dp[x][y]
    else:
        dp[x][y] = 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if forest[nx][ny] > forest[x][y]:
                    dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1)
        return dp[x][y]
        
def solve():
    global dp
    result = 0
    
    for i in range(n):
        for j in range(n):
            if not dp[i][j]:
                result = max(result, dfs(i, j))

    print(result)
            

if __name__ == '__main__':
    solve()