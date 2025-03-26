import sys

n = int(input())
home = [list(map(int, input().split())) for _ in range(n)]
# 0은 가로, 1은 대각선, 2는 세로로
dp = [[[0] * n for _ in range(n)] for _ in range(3)]

def solve():
    dp[0][0][1] = 1
    
    # 0행의 가로 파이프는 각 위치에서 1개 방법만 존재
    for i in range(2, n):
        if not home[0][i]:
            dp[0][0][i] = dp[0][0][i - 1]
        
    # 1행과 1열부터 N -1행과 N - 1열까지 각각의 가능 파이프의 수를 찾기
    for i in range(1, n):
        for j in range(1, n):
            # 현재 칸에 파이프를 놓을 수 있는지 확인
            if not home[i][j]:
                # 대각선 파이프의 개수
                if home[i - 1][j] == 0 and home[i][j - 1] == 0:
                    dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1]
                
                # 가로, 세로 파이프의 개수
                dp[0][i][j] = dp[0][i][j - 1] + dp[1][i][j - 1]
                dp[2][i][j] = dp[2][i - 1][j] + dp[1][i - 1][j]

    print(sum(dp[i][n - 1][n - 1] for i in range(3)))
    

if __name__ == '__main__':
    solve()