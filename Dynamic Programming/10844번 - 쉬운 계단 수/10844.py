import sys

input = sys.stdin.readline

n = int(input())
dp = [list(0 for _ in range(10)) for _ in range(n+1)]

def solve():
    for i in range(1, 10):
        dp[1][i] = 1
    for i in range(2, n + 1):
        for j in range(10):
            dp[i][j] = dp[i-1][1] if j == 0 else (dp[i-1][8] if j == 9 else dp[i-1][j-1] + dp[i-1][j+1])
        dp[i][j] %= 1000000000
    
    print(sum(dp[n]) % 1000000000)

if __name__ == '__main__':
    solve()