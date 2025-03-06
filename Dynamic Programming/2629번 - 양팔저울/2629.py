import sys

input = sys.stdin.readline

n = int(input())
scale = list(map(int, input().split())) + [0]
m = int(input())
weights = list(map(int, input().split()))
dp = [[False for _ in range(15001)] for _ in range(31)]

def dfs(cnt, sum_w):
    if cnt > n or dp[cnt][sum_w]:
        return

    dp[cnt][sum_w] = True
    
    dfs(cnt + 1, sum_w + scale[cnt])
    dfs(cnt + 1, abs(sum_w - scale[cnt]))
    dfs(cnt + 1, sum_w)

def solve():
    dfs(0, 0)
    
    ans = []
    for w in weights:
        if w > 15000:
            ans.append('N')
        elif dp[n][w]:
            ans.append('Y')
        else:
            ans.append('N')
    print(*ans)

if __name__ == '__main__':
    solve()