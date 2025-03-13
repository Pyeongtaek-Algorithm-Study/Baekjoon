import sys
sys.setrecursionlimit(10**7)

def dfs(x, y):
    vis[x][y] = True
    
    for d in [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]:
        nx = x + d[0]
        ny = y + d[1]
        
        if (0 <= nx < h) and (0 <= ny < w):
            if board[nx][ny] == 1 and not vis[nx][ny]:
                dfs(nx, ny)

def solve():
    ans = 0
    
    for i in range(h):
        for j in range(w):
            if board[i][j] and not vis[i][j]:
                ans += 1
                dfs(i, j)
    
    print(ans)

if __name__ == '__main__':
    while True:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break
        board = [list(map(int, input().split())) for _ in range(h)]
        vis = [[False] * (w) for _ in range(h)]
        solve()