import sys

input = sys.stdin.readline

n, m = map(int, input().split())
stu = [[0] * n for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    stu[a][b] = 1

def solve():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if stu[i][k] and stu[k][j]:
                    stu[i][j] = 1
    
    ans = 0
    for i in range(n):
        if sum(stu[i]) + sum(st[i] for st in stu) == n - 1:
            ans += 1
    print(ans)

if __name__ == '__main__':
    solve()