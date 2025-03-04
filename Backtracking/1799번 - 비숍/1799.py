import sys

input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
ans = [0, 0]
l = [0] * 20
r = [0] * 20

def tracking(row, col, cnt, color):
    if col >= n:
        row += 1
        if col % 2 == 0:
            col = 1
        else:
            col = 0
    
    if row >= n:
        ans[color] = max(ans[color], cnt)
        return
    
    if board[row][col] and not l[col - row + n - 1] and not r[row + col]:
        l[col - row + n - 1] = r[row + col] = 1
        tracking(row, col + 2, cnt + 1, color)
        l[col - row + n - 1] = r[row + col] = 0
    tracking(row, col + 2, cnt, color)

def solve():
    tracking(0, 0, 0, 0)
    tracking(0, 1, 0, 1)
    
    print(ans[0] + ans[1])

if __name__ == '__main__':
    solve()