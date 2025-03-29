import sys

input = sys.stdin.readline

n, m, h = map(int, input().split())
students = [0] + [list(map(int, input().split()))for _ in range(n)]
dp = [[0] * (h + 1) for _ in range(n + 1)]

def solve():
    for i in range(n + 1):
        dp[i][0] = 1

    
    for i in range(1, n + 1):
        for j in range(1, h + 1):
            for k in students[i]:
                if j >= k:
                    dp[i][j] += dp[i - 1][j - k]
                    dp[i][j] %= 10007
                    
            dp[i][j] += dp[i - 1][j]
            dp[i][j] %= 10007

    print(dp[n][h])    
    
if __name__ == '__main__':
    solve()