import sys
import heapq

input = sys.stdin.readline

n, e = map(int, input().split())
arr = [list() for _ in range(n+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    arr[a].append([b, c])
    arr[b].append([a, c])
v1, v2 = map(int, input().split())
INF = 10**7

def dijkstra(st):
    min_val = [INF] * (n + 1)
    min_val[st] = 0
    hq = []
    heapq.heappush(hq, [0, st])
    
    while hq:
        weight, node = heapq.heappop(hq)
        
        if min_val[node] < weight:
            continue
        
        for info in arr[node]:
            next_node = info[0]
            next_weight = info[1] + weight
            
            if min_val[next_node] > next_weight:
                min_val[next_node] = next_weight
                heapq.heappush(hq, [next_weight, next_node])
    
    return min_val

def solve():
    case_1, case_2 = 0, 0
    
    dij_1 = dijkstra(1)
    case_1 += dij_1[v1]
    case_2 += dij_1[v2]
    
    dij_v1 = dijkstra(v1)
    case_1 += dij_v1[v2]
    case_2 += dij_v1[n]
    
    dij_v2 = dijkstra(v2)
    case_1 += dij_v2[n]
    case_2 += dij_v2[v1]
    
    ans = min(case_1, case_2)
    print(ans if ans < INF else -1)

if __name__ == '__main__':
    solve()