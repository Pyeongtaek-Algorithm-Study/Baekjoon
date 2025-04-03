import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
goods = [list(0 for _ in range(n)) for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    goods[a][b] = 1
    goods[b][a] = -1

def solve():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if goods[i][k] == goods[k][j] and goods[i][k] != 0:
                    goods[i][j] = goods[i][k]
    
    for el in goods:
        cnt = n - 1
        for e in el:
            if e != 0:
                cnt -= 1
        print(cnt)

if __name__ == '__main__':
    solve()