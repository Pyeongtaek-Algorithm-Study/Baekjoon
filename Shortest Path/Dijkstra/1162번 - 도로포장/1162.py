import sys
import heapq

input = sys.stdin.readline

INF = 10**15

n, m, k = map(int, input().split())
edges = list([] for _ in range(n + 1))
for _ in range(m):
    a, b, c = map(int, input().split())
    edges[a].append((b, c))
    edges[b].append((a, c))

def solve():
    dp = [[INF] * (n + 1) for _ in range(k + 1)]
    hq = []
    heapq.heappush(hq, [0, 1, 0])
    
    while hq:
        weight, node, cnt = heapq.heappop(hq)
        
        if dp[cnt][node] < weight:
            continue
        
        for nxt_node, nxt_weight in edges[node]:
            nxt_weight += weight
            
            if dp[cnt][nxt_node] > nxt_weight:
                dp[cnt][nxt_node] = nxt_weight
                heapq.heappush(hq, [nxt_weight, nxt_node, cnt])
            
            if cnt + 1 <= k and dp[cnt + 1][nxt_node] > weight:
                dp[cnt + 1][nxt_node] = weight
                heapq.heappush(hq, [weight, nxt_node, cnt + 1])
                
    print(min(dp[i][n] for i in range(1, k + 1)))

if __name__ == '__main__':
    solve()