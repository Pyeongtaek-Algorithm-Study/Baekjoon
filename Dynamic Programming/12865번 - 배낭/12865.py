import sys

input = sys.stdin.readline

n, k = map(int, input().split())
dp = [0] * (k + 1)

def solve():
    for _ in range(n):
        w, v = map(int, input().split())
        for i in range(k, w - 1, -1):
            dp[i] = max(dp[i], dp[i - w] + v)
        
    print(dp[k])

if __name__ == '__main__':
    solve()