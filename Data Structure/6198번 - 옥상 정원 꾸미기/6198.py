import sys

input = sys.stdin.readline

n = int(input())
arr = list(int(input()) for _ in range(n))

def solve():
    roof = []
    ans = 0
    
    for el in arr:
        while len(roof) and roof[-1] <= el:
            roof.pop()
        ans += len(roof)
        roof.append(el)
    
    print(ans)

if __name__ == '__main__':
    solve()