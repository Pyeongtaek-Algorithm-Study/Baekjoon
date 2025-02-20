import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

BIG_NUM = 10**7

def bfs(c, r):
    Q = deque()
    vis = list([0] * w for _ in range(h))
    Q.append([c, r])
    vis[c][r] = 1
    
    while Q:
        x, y = Q.popleft()
        
        for dd in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx = x + dd[0]
            ny = y + dd[1]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                continue
            if board[nx][ny] == 'x' or vis[nx][ny]:
                continue
            
            vis[nx][ny] = vis[x][y] + 1
            Q.append([nx, ny])
            
    return vis

if __name__ == '__main__':
    while True:
        w, h = map(int, input().split())
        if not w and not h:
            break
        
        board, dusts = [], []
        for i in range(h):
            board.append(input().rstrip())
            for j, k in enumerate(board[i]):
                if k == 'o':
                    rc, rr = i, j
                elif k == '*':
                    dusts.append([i, j])
                    
        r2d, possible = [], True
        robot_possible_board = bfs(rc, rr)
        for x, y in dusts:
            if not robot_possible_board[x][y]:
                possible = False
                break
            r2d.append(robot_possible_board[x][y] - 1)
        if not possible:
            print(-1)
            continue
        
        
        d2d = list([0] * len(dusts) for _ in range(len(dusts)))
        for i in range(len(dusts) - 1):
            dust_st = bfs(dusts[i][0], dusts[i][1])
            for j in range(i + 1, len(dusts)):
                d2d[i][j] = dust_st[dusts[j][0]][dusts[j][1]] - 1
                d2d[j][i] = d2d[i][j]
                
        ans = BIG_NUM
        p = list(permutations([i for i in range(len(d2d))]))
        print(p)
        for i in p:
            dist = 0
            dist += r2d[i[0]]
            nfrom = i[0]
            for j in range(1, len(i)):
                nto = i[j]
                dist += d2d[nfrom][nto]
                nfrom = nto

            ans = min(ans, dist)
        print(ans)