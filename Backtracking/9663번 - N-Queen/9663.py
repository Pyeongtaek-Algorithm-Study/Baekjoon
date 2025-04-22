import sys

input = sys.stdin.readline

n = int(input())
ans = 0

def back(x, col):
    global ans

    if x == n:
        ans += 1
        return

    for i in range(n):
        col[x] = i
        chk = True
        
        for j in range(x):
            if col[x] == col[j] or abs(col[x] - col[j]) == x - j:
                chk = False
                break
        
        if chk:
            back(x + 1, col)

def solve():
    back(0, [0] * n)
    
    print(ans)
    

if __name__ == '__main__':
    solve()