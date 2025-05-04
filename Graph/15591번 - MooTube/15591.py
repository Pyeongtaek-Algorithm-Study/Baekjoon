import sys
from collections import deque, defaultdict

input = sys.stdin.readline

n, m = map(int, input().split())
edges = defaultdict(list)

for _ in range(n - 1):
    p, q, r = map(int, input().split())
    edges[p].append((q, r))
    edges[q].append((p, r))
    
output = [list(map(int, input().split())) for _ in range(m)]
    
def bfs(k, v):
    Q = deque()
    Q.append(v)
    vis = [False] * (n + 1)
    
    while Q:
        cur = Q.popleft()
        vis[cur] = True
        
        for nxt, usado in edges[cur]:
            if vis[nxt] or k > usado:
                continue
            
            vis[nxt] = True
            Q.append(nxt)
            
    # 자기 자신의 True는 개수는 제외
    return vis.count(True) - 1
    

def solve():
    for k, v in output:
        ans = bfs(k, v)
        print(ans)

if __name__ == '__main__':
    solve()