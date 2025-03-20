import sys
from collections import deque

input = sys.stdin.readline

n, m, k = map(int, input().split())
soil = [list(map(int, input().split())) for _ in range(n)]
ground = [[5] * n for _ in range(n)]
trees = [[deque() for _ in range(n)] for _ in range(n)]
for _ in range(m):
    x, y, z = map(int, input().split())
    trees[x-1][y-1].append(z)
    
def spring_summer():
    for i in range(n):
        for j in range(n):
            # spring
            cnt = 0
            for idx in range(len(trees[i][j])):
                if trees[i][j][idx] <= ground[i][j]:
                    ground[i][j] -= trees[i][j][idx]
                    trees[i][j][idx] += 1
                    cnt += 1
                else:
                    break
            
            # summer
            while cnt < len(trees[i][j]):
                ground[i][j] += (trees[i][j].pop() // 2)

def fall_winter():
    for i in range(n):
        for j in range(n):
            # fall
            plus = len([tree for tree in trees[i][j] if tree % 5 == 0])
            for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0], [1, 1], [1, -1], [-1, 1,], [-1, -1]]:
                nx = i + dx
                ny = j + dy
                
                if 0 <= nx < n and 0 <= ny < n:
                    for _ in range(plus):
                        trees[nx][ny].appendleft(1) 
            
            # winter
            ground[i][j] += soil[i][j]
    
def solve():
    for _ in range(k):
        spring_summer()
        fall_winter()
    
    ans = 0
    for i in range(n):
        for j in range(n):
            ans += len(trees[i][j])
    
    print(ans)
    

if __name__ == '__main__':
    solve()