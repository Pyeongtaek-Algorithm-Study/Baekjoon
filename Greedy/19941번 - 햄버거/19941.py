import sys

input = sys.stdin.readline

n, k = map(int, input().split())
table = list(input().rstrip())

def solve():
    ans = 0
    
    for i in range(n):
        if table[i] != 'P':
            continue
        
        for j in range(max(i - k, 0), min(i + k + 1, n)):
            if table[j] == 'H':
                table[j] = '-'
                ans += 1
                break
    
    print(ans)

if __name__ == '__main__':
    solve()