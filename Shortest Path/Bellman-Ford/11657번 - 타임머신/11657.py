import sys

input = sys.stdin.readline

INF = 10**9

n, m = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(m)]
min_cost = [INF] * (n + 1)

def solve():
    min_cost[1] = 0
    
    for _ in range(n):
        for edge in edges:
            st, end, cost = edge[0], edge[1], edge[2]
            nxt_cost = min_cost[st] + cost
            
            if min_cost[st] == INF or min_cost[end] < nxt_cost:
                continue
            min_cost[end] = nxt_cost
            
    for edge in edges:
        st, end, cost = edge[0], edge[1], edge[2]
        nxt_cost = min_cost[st] + cost
        
        if min_cost[st] != INF and min_cost[end] > nxt_cost:
            print(-1)
            exit(0)
                
    for i in range(2, n + 1):
        print(-1 if min_cost[i] == INF else min_cost[i])
                
                

if __name__ == '__main__':
    solve()