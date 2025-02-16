import sys
from collections import deque

input = sys.stdin.readline

n, l = map(int, input().split())
nums = list(map(int, input().split()))

def solve():
    dq = deque()
    for i in range(n):
        if dq and dq[0][1] <= i - l:
            dq.popleft()
        
        while dq and dq[-1][0] >= nums[i]:
            dq.pop()
            
        dq.append([nums[i], i])
        
        print(dq[0][0], end=' ')

if __name__ == '__main__':
    solve()