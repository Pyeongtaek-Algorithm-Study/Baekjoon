import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

def solve():
    ans = 0
    
    sorted_arr = sorted(arr)
    l, r = 0, n - 1
    while l < r:
        k = sorted_arr[l] + sorted_arr[r]
        
        if k <= x:
            if k == x:
                ans += 1
            l += 1
        else:
            r -= 1
    
    print(ans)

if __name__ == '__main__':
    solve()