import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = list(list(False for _ in range(n)) for _ in range(n))

def solve():
    for i in range(n):
        dp[i][i] = True
    for i in range(n):
        for j in range(n):
            if i + 1 == j and arr[i] == arr[j]:
                dp[i][j] = True
    for i in range(2, n):
        for j in range(n - i):
            if arr[j] == arr[i + j] and dp[j + 1][i + j - 1]:
                dp[j][j+ i] = True
    
    m = int(input())
    for _ in range(m):
        s, e = map(int, input().split())
        print(1 if dp[s-1][e-1] else 0)

if __name__ == '__main__':
    solve()