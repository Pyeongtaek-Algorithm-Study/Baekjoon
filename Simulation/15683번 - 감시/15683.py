import sys
import copy

input = sys.stdin.readline

n, m = map(int, input().split())
arr = []
cctv = []
for i in range(n):
    arr_idx = list(map(int, input().split()))
    for j in range(m):
        if arr_idx[j] != 0 and arr_idx[j] != 6:
            cctv.append([i, j])
    arr.append(arr_idx)
ans = 10**7

def view(x, y, d):
    d %= 4
    v = [[0, -1], [-1, 0], [0, 1], [1, 0]]
    dx = v[d][0]
    dy = v[d][1]
    
    while(1):
        x += dx
        y += dy
        if 0 <= x < n and 0 <= y < m and arr[x][y] != 6:
            if arr[x][y] != 0:
                continue
            arr[x][y] = -1
        else:
            break

def dfs(cnt):
    global arr, ans
    
    if cnt == len(cctv):
        zero = 0
        for i in range(n):
            for j in range(m):
                if arr[i][j] == 0:
                    zero += 1
        ans = min(ans, zero)
        return
        
    tmp = copy.deepcopy(arr)
    x = cctv[cnt][0]
    y = cctv[cnt][1]
    for dd in range(4):
        if arr[x][y] == 1:
            view(x, y, dd)
        elif arr[x][y] == 2:
            view(x, y, dd)
            view(x, y, dd + 2)
        elif arr[x][y] == 3:
            view(x, y, dd)
            view(x, y, dd + 1)
        elif arr[x][y] == 4:
            view(x, y, dd)
            view(x, y, dd + 1)
            view(x, y, dd + 2)
        elif arr[x][y] == 5:
            view(x, y, dd)
            view(x, y, dd + 1)
            view(x, y, dd + 2)
            view(x, y, dd + 3)
            
        dfs(cnt + 1)
        arr = copy.deepcopy(tmp)

def solve():
    dfs(0)
    print(ans)
    
if __name__ == '__main__':
    solve()