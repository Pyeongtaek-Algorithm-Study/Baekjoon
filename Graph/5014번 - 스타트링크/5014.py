import sys
from collections import deque

input = sys.stdin.readline

INF = float('inf')

f, s, g, u, d = map(int, input().split())

def solve():
    elevator = [INF] * (f + 1)
    q = deque()
    q.append(s)
    elevator[s] = 0
    
    while q:
        cur = q.popleft()
        up_f, down_f = cur + u, cur - d
        nxt_cnt = elevator[cur] + 1
        
        if up_f <= f and elevator[up_f] > nxt_cnt:
            elevator[up_f] = nxt_cnt
            q.append(up_f)
        if down_f >= 1 and elevator[down_f] > nxt_cnt:
            elevator[down_f] = nxt_cnt
            q.append(down_f)
    
    print(elevator[g] if elevator[g] != INF else "use the stairs")
            

if __name__ == '__main__':
    solve()