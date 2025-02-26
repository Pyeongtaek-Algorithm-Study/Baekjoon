import sys

input = sys.stdin.readline

def test_case():
    c = int(input())
    coins = map(int, input().split())
    m = int(input())
    
    dp = [0] * (m + 1)
    dp[0] = 1
    
    for coin in coins:
        for j in range(coin, m + 1):
            dp[j] += dp[j - coin]
    
    print(dp[m])

def solve():
    t = int(input())
    for _ in range(t):
        test_case()

if __name__ == '__main__':
    solve()