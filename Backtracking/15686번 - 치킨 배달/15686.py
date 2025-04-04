import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n, m = map(int, input().split())
town = [list(map(int, input().split())) for _ in range(n)]
houses = [(i, j) for j in range(n) for i in range(n) if town[i][j] == 1]
chickens = [(i, j) for j in range(n) for i in range(n) if town[i][j] == 2]
ans = float('inf')

def back(cur, selected):
    global ans
    
    if len(selected) == m:
        dist_sum = 0

        for hx, hy in houses:
            dist = float('inf')
            for sx, sy in selected:
                dist = min(dist, abs(hx - sx) + abs(hy - sy))
            
            dist_sum += dist
            
        ans = min(ans, dist_sum)
        return
    
    for nxt in range(cur, len(chickens)):
        selected.append(chickens[nxt])
        back(nxt + 1, selected)
        selected.pop()

def solve():
    back(0, [])
    
    print(ans)

if __name__ == '__main__':
    solve()
