import sys
from collections import deque

input = sys.stdin.readline

LIM = 100001

def solve(n, k):
    dq = deque()
    dq.append(n)
    
    vis = [-1] * LIM
    vis[n] = 0
    
    while dq:
        cur = dq.popleft()
        
        if cur == k:
            print(vis[cur])
        
        for nxt in [cur - 1, cur + 1, cur * 2]:
            if (nxt < 0 or nxt >= LIM) or vis[nxt] != -1:
                continue
            
            if nxt == cur * 2:
                vis[nxt] = vis[cur]
                dq.appendleft(nxt)
            else:
                vis[nxt] = vis[cur] + 1
                dq.append(nxt)
                
    

if __name__ == '__main__':
    n, k = map(int, input().split())
    solve(n, k)