import sys
import heapq

input = sys.stdin.readline

def dijkstra(st, com, sec_arr):
    hq = []
    sec_arr[st] = 0
    heapq.heappush(hq, [0, st])
    
    while hq:
        weight, node = heapq.heappop(hq)
        
        if(sec_arr[node] < weight):
            continue
        
        for el in com[node]:
            next_node, next_weight = el
            next_weight += weight
            
            if sec_arr[next_node] > next_weight:
                sec_arr[next_node] = next_weight
                heapq.heappush(hq, [next_weight, next_node])
            
    cnt, total_sec = 0, 0    
    for sec in sec_arr:
        if sec != 1e9:
            cnt += 1
            total_sec = max(total_sec, sec)
    
    print(cnt, total_sec)


def solve():
    t = int(input())
    while t:
        n, d, c = map(int, input().split())
        arr = [[] for _ in range(n + 1)]
        for _ in range(d):
            a, b, s = map(int, input().split())
            arr[b].append([a, s])
        min_sec = [1e9 for _ in range(n + 1)]
        dijkstra(c, arr, min_sec)
        t -= 1

if __name__ == '__main__':
    solve()