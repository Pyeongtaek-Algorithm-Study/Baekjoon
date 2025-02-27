import sys

input = sys.stdin.readline

n = int(input())
coin = list(map(int, input().split()))

def solve():
    ans = 1
    sorted_coin = sorted(coin)
    
    for c in sorted_coin:
        if ans < c: 
            break
        ans += c
    
    print(ans)

if __name__ == '__main__':
    solve()