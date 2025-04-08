import sys

input = sys.stdin.readline

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
vis = [[False] * m for _ in range(n)]

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

# 그냥 구현
tets = [
    # ㅣ 모양
    [(0, 1), (0, 2), (0, 3)], [(1, 0), (2, 0), (3, 0)],
    # ㅁ 모양
    [(0, 1), (1, 0,), (1, 1)],
    # ㄴ 모양
    [(0, 1), (-1, 0), (-2, 0)], [(1, 0), (0, 1), (0, 2)], [(0, -1), (1, 0), (2, 0)], [(-1, 0), (0, -1), (0, -2)],
    [(0, -1), (-1, 0), (-2, 0)], [(-1, 0), (0, 1), (0, 2)], [(0, 1), (1, 0), (2, 0)], [(1, 0), (0, -1), (0, -2)],
    # ㄹ 모양
    [(1, 0), (1, 1), (2, 1)], [(0, 1), (-1, 1), (-1, 2)], [(-1, 0), (-1, 1), (-2, 1)], [(0, 1), (1, 1), (1, 2)],
    # ㅗ 모양
    [(-1, -1), (-1, 0), (-1, 1)], [(-1, 1), (0, 1), (1, 1)], [(1, -1), (1, 0), (1, 1)], [(-1, -1), (0, -1), (1, -1)]
    ]

ans = 0

def back(x, y, cnt, total):
    global ans
    if cnt == 4:
        ans = max(ans, total)
        return
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
            vis[nx][ny] = True
            back(nx, ny, cnt + 1, total + paper[nx][ny])
            vis[nx][ny] = False


def t(x, y):
    global ans

    for d in range(4):
        t_total = paper[x][y]
        for i in range(4):
            if d == i:
                continue
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m:
                t_total += paper[nx][ny]
        
        if ans < t_total:
            ans = t_total
            

def shape(x, y, tet):
    temp = paper[x][y]
    
    for dx, dy in tet:
        nx = x + dx
        ny = y + dy
        
        if 0 <= nx < n and 0 <= ny < m:
            temp += paper[nx][ny]
        
        else:
            return -1
    
    return temp

def solve():
    # Backtracking 으로 구현
    # for i in range(n):
    #     for j in range(m):
    #         vis[i][j] = True
    #         back(i, j, 1, paper[i][j])
    #         vis[i][j] = False
    #         t(i, j)
    
    # 모양 구현으로 전부 조사
    ans = 0
    
    for i in range(n):
        for j in range(m):
            for tet in tets:
                sum_paper = shape(i, j, tet)
                if ans < sum_paper:
                    ans = sum_paper
    
    print(ans)

if __name__ == '__main__':
    solve()