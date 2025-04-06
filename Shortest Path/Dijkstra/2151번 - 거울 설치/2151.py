import sys
from collections import deque
import heapq

input = sys.stdin.readline

INF = float('inf')

n = int(input())
home = [input().rstrip() for _ in range(n)]
door = []
for i in range(n):
    for j in range(n):
        if home[i][j] == '#':
            door.append((i, j))

def solve():
    # 각 칸마다 4방향의 거울 개수 기록
    vis = [[[INF] * 4 for _ in range(n)] for _ in range(n)]
    hq = []
    for i in range(4):
        heapq.heappush(hq, (0, door[0], i))
    
    dx = [0, -1, 0, 1]
    dy = [-1, 0, 1, 0]
    
    while hq:
        cnt, (coor_x, coor_y), d = heapq.heappop(hq)
        
        nx = coor_x + dx[d]
        ny = coor_y + dy[d]
        
        # 가장 적은 거울 개수일 때의 다른 문에 도착 시
        if door[1] == (nx, ny):
            print(cnt)
            break
        
        if nx < 0 or nx >= n or ny < 0 or ny >= n or home[nx][ny] == '*':
            continue
        
        # 다음 방문 칸의 방향의 거울 개수를 더 작게 가능한 경우
        if vis[nx][ny][d] > cnt:
            vis[nx][ny][d] = cnt
            heapq.heappush(hq, (cnt, (nx, ny), d))
            
        # 다음 방문 칸에 거울을 설치가 가능한 경우
        if home[nx][ny] == '!':
            ld, rd = (d + 3) % 4, (d + 1) % 4
            
            # 거울을 좌측 방향으로 했을 때
            if vis[nx][ny][ld] > cnt + 1:
                vis[nx][ny][ld] = cnt + 1
                heapq.heappush(hq, (cnt + 1, (nx, ny), ld))
                
            # 거울을 우측 방향으로 했을 때
            if vis[nx][ny][rd] > cnt + 1:
                vis[nx][ny][rd] = cnt + 1
                heapq.heappush(hq, (cnt + 1, (nx, ny), rd))


if __name__ == '__main__':
    solve()