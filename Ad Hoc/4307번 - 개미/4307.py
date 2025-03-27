import sys

input = sys.stdin.readline

def solve(l, n, ant):
    ans_min, ans_max = 0, 0
    
    while n:
        n -= 1
        sht, lon = min(ant[n], l - ant[n]), max(ant[n], l - ant[n])
        ans_min = max(ans_min, sht)
        ans_max = max(ans_max, lon)
        
    print(ans_min, ans_max)


if __name__ == '__main__':
    tc = int(input())
    while tc:
        l, n = map(int, input().split())
        ant = [int(input()) for _ in range(n)]
        solve(l, n, ant)
        tc -= 1