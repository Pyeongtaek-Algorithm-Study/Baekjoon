import sys
import heapq

input = sys.stdin.readline

INF = 10**7

n, m, r = map(int, input().split())
items = list(map(int, input().split()))
edges = [[] for _ in range(n + 1)]
for _ in range(r):
    a, b, c = map(int, input().split())
    edges[a].append((b, c))
    edges[b].append((a, c))
    
def dijkstra(st):
    dist = [INF] * (n + 1)
    dist[st] = 0
    possible_item_cnt = 0
    hq = []
    heapq.heappush(hq, (0, st))
    
    while hq:
        weight, node = heapq.heappop(hq)
        
        if dist[node] < weight or dist[node] > m:
            continue
        
        possible_item_cnt += items[node - 1]
        
        for nxt_node, nxt_weight in edges[node]:
            nxt_weight += weight
            
            if dist[nxt_node] > nxt_weight:
                dist[nxt_node] = nxt_weight
                heapq.heappush(hq, (nxt_weight, nxt_node))
    
    return possible_item_cnt

def solve():
    ans = []
    
    for i in range(1, n + 1):
        ans.append(dijkstra(i))
        
    print(max(ans))

if __name__ == '__main__':
    solve()