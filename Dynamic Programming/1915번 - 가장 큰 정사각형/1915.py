import sys

input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(list(0 for _ in range(m)) for _ in range(n))
for i in range(n):
    line = input()
    for j in range(m):
        arr[i][j] = int(line[j])
dp = list(list(0 for _ in range(m + 1)) for _ in range(n + 1))

def solve():
    max_side = 0
    for i in range(n):
        for j in range(m):
            dp[i + 1][j + 1] = min(dp[i][j+1], dp[i][j], dp[i+1][j]) + 1 if arr[i][j] else 0
            max_side = max(max_side, dp[i + 1][j + 1])

    print(max_side**2)

if __name__ == '__main__':
    solve()