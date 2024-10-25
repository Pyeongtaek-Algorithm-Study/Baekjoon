import sys
import heapq

input = sys.stdin.readline

n, m, x = map(int, input().split())
graph = list([] for _ in range(n + 1))
reverse_graph = list([] for _ in range(n + 1))
INF = int(1e9)

for _ in range(m):
    s, d, t = map(int, input().split())
    graph[s].append([t, d])
    reverse_graph[d].append([t, s])
    
def dijkstra(graph, st):
    min_dist = [INF] * (n + 1) 
    q = []
    heapq.heappush(q, (0, st))
    min_dist[st] = 0
    
    while q:
        weight, dest = heapq.heappop(q)
        
        if min_dist[dest] < weight: 
            continue
        
        for g in graph[dest]:
            next_weight, next_dest = g
            next_weight += weight
            if next_weight < min_dist[next_dest]:
                min_dist[next_dest] = next_weight
                heapq.heappush(q, (next_weight, next_dest))
                
    return min_dist
        

def solve():
    # X -> graph
    come = dijkstra(graph, x)
    # graph -> X
    go = dijkstra(reverse_graph, x)
    
    total_dist = []
    for i in range(1, n + 1):
        total_dist.append(come[i] + go[i])
        
    print(max(total_dist))
    
if __name__ == '__main__':
    solve()