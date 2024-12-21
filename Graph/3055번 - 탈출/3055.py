import sys
from collections import deque

input = sys.stdin.readline

r, c = map(int, input().split())
forest = [ input().rstrip() for _ in range(r) ]
dist = list( [10001 for _ in range(c)] for _ in range(r))

def bfs(Q, is_water):
    dx = [0, -1, 0, 1]
    dy = [-1, 0, 1, 0]
    
    while len(Q) != 0:
        cur = Q.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            
            if nx < 0 or nx >= r or ny < 0 or ny >= c:
                continue
            if (forest[nx][ny] == 'X' or (is_water and forest[nx][ny] == 'D') or  
                dist[nx][ny] <= dist[cur[0]][cur[1]] + 1):
                continue
            dist[nx][ny] = dist[cur[0]][cur[1]] + 1
            Q.append([nx, ny])
    

def solve():
    flow = deque()
    biber = deque()
    
    for i in range(r):
        for j in range(c):
            if forest[i][j] == '*':
                
                dist[i][j] = 0
                flow.append([i, j])
            if forest[i][j] == 'S':
                st_x, st_y = i, j
                biber.append([i, j])
            if forest[i][j] == 'D':
                end_x, end_y = i, j
                
    bfs(flow, True)
    dist[st_x][st_y] = 0
    bfs(biber, False)

    print(dist[end_x][end_y] if dist[end_x][end_y] != 10001 else 'KAKTUS')

if __name__ == '__main__':
    solve()