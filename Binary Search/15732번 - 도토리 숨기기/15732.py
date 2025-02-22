import sys

input = sys.stdin.readline

n, k, d = map(int, input().split())
rule = []
for _ in range(k):
    a, b, c = map(int, input().split())
    rule.append([a, b, c])

def solve():
    l, r = 0, n
    mid = 0
    ans = 0
    
    while l <= r:
        total = 0
        mid = (l + r) // 2
        
        for i in range(k):
            last = min(mid, rule[i][1])
            if last >= rule[i][0]:
                total += (last - rule[i][0]) // rule[i][2] + 1
            
        if total >= d:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
            
    print(ans)

if __name__ == '__main__':
    solve()