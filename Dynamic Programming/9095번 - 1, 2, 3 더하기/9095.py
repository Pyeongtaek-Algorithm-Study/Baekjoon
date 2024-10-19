import sys

input = sys.stdin.readline

def solve():
    dp = [0, 1, 2, 4] + [0] * 10
    for i in range(4, 12):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        
    for _ in range(int(input())):
        print(dp[int(input())])
    
if __name__ == '__main__':
    solve()