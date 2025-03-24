import sys
import heapq

input = sys.stdin.readline

INF = float('inf')

m, n = map(int, input().split())
board = [list(map(int, input().rstrip())) for _ in range(n)]
vis = [[INF] * m for _ in range(n)]

def dijkstra():
    hq = []
    heapq.heappush(hq, [0, 0, 0])
    vis[0][0] = 0
    
    while hq:
        cost, x, y = heapq.heappop(hq)
        
        for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < n and 0 <= ny < m and (vis[nx][ny] > vis[x][y] + board[nx][ny]):
                vis[nx][ny] = vis[x][y] + board[nx][ny]
                heapq.heappush(hq, [vis[nx][ny], nx, ny])

def solve():
    dijkstra()
    
    print(vis[n-1][m-1])

if __name__ == '__main__':
    solve()