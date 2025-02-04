import sys
from collections import deque
sys.setrecursionlimit(10**7)

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().rstrip())) for _ in range(n)]
area_arr = [list(0 for _ in range(m)) for _ in range(n)]
vis = [list(False for _ in range(m)) for _ in range(n)]

def dfs(x, y, cnt, area_num):
    vis[x][y] = True
    area_arr[x][y] = area_num
    
    for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
        nx = x + dx
        ny = y + dy
        
        if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
            if arr[nx][ny] == 0:
                cnt = max(cnt, dfs(nx, ny, cnt + 1, area_num))

    return cnt
            

def solve():
    area_dict = dict()
    area = -1
    walls = []
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0 and not vis[i][j]:
                t = dfs(i, j, 1, area)
                area_dict[area] = t
                area -= 1
            elif arr[i][j] == 1:
                walls.append([i, j])
    
    for wall in walls:
        x = wall[0]
        y = wall[1]
        ans_list = []
        
        for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < n and 0 <= ny < m and area_arr[nx][ny] < 0:
                ans_list.append(area_arr[nx][ny])
                
        ans_list = list(set(ans_list))
        
        # divide 10
        for el in ans_list:
            arr[x][y] += area_dict[el]
        arr[x][y] %= 10
    
    # answer
    for i in arr:
        print(''.join(map(str, i)))
        

if __name__ == '__main__':
    solve()