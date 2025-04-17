import sys
from collections import defaultdict

input = sys.stdin.readline

def solve(n, k, arr):
    left, seq_len = 0, 0
    cnt = defaultdict(int)
    ans = 0
    
    for right in range(n):
        cnt[arr[right]] += 1
        
        while cnt[arr[right]] > k:
            cnt[arr[left]] -= 1
            
            if cnt[arr[left]] == 0:
                del cnt[arr[left]]
                
            left += 1
        
        ans = max(ans, right - left + 1)
    
    print(ans)

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    solve(n, k, arr)