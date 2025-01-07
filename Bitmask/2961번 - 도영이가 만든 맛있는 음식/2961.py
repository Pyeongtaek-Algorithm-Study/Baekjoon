import sys

input = sys.stdin.readline

n = int(input())
ingre = []
for _ in range(n):
    a, b = map(int, input().split())
    ingre.append([a, b])

def solve():
    ans = 1e9
    
    for i in range(1, (1 << n)):
        a, b = 1, 0
        for j in range(n):
            if i & (1 << j):
                a *= ingre[j][0]
                b += ingre[j][1]
        ans = min(ans, abs(a - b))
        
    print(ans)

if __name__ == '__main__':
    solve()