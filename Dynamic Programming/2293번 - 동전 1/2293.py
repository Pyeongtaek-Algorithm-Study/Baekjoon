import sys

input = sys.stdin.readline

def solve(n, k, coins):
    dp = [0] * (k + 1)
    dp[0] = 1
    
    for coin in coins:
        for i in range(coin, k + 1):
            dp[i] += dp[i - coin]
            
    print(dp[k])

if __name__ == '__main__':
    n, k = map(int, input().split())
    coins = [int(input()) for _ in range(n)]
    solve(n, k, coins)