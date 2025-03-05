import sys
from collections import deque

input = sys.stdin.readline

def solve():
    ans = 0
    Q = deque()
    for i in range(1, m + 1):
        if not degree[i]:
            strahler[i][0] = 1
            Q.append(i)
            
    while Q:
        cur = Q.popleft()
        ans = max(ans, strahler[cur][0])
        
        for ncur in river[cur]:
            if strahler[ncur][0] < strahler[cur][0]:
                strahler[ncur][0] = strahler[cur][0]
                strahler[ncur][1] = False
            elif strahler[ncur][0] == strahler[cur][0] and not strahler[ncur][1]:
                strahler[ncur][0] += 1
                strahler[ncur][1] = True
                
            degree[ncur] -= 1
            if degree[ncur] == 0:
                Q.append(ncur)
                
    print(k, ans)

if __name__ == '__main__':
    tc = int(input())
    while tc:
        k, m, p = map(int, input().split())
        river = list([] for _ in range(m + 1))
        degree = list([0] * (m + 1))
        strahler = list([0, False] for _ in range(m + 1))
        for _ in range(p):
            a, b = map(int, input().split())
            river[a].append(b)
            degree[b] += 1
        solve()
        
        tc -= 1