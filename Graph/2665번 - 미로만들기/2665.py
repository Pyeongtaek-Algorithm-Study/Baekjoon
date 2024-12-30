import sys
from collections import deque

input = sys.stdin.readline
mx = 987654321

n = int(input())
room = [list(map(int, input().rstrip())) for _ in range(n)]
vis = [list(mx for _ in range(n))for _ in range(n)]

def BFS():
    dx = [0, -1, 0, 1]
    dy = [-1, 0, 1, 0]
    vis[0][0] = 0
    Q = deque()
    Q.append([0, 0])
    while len(Q) != 0:
        x, y = Q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if room[nx][ny] == 1 and vis[nx][ny] > vis[x][y]:
                    vis[nx][ny] = vis[x][y]
                    Q.append([nx, ny])
                elif room[nx][ny] == 0 and vis[nx][ny] > vis[x][y] + 1:
                    vis[nx][ny] = vis[x][y] + 1
                    Q.append([nx, ny])

def solve():
    BFS()
    print(vis[n-1][n-1])

if __name__ == '__main__':
    solve()