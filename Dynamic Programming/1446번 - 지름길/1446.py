import sys
import heapq

input = sys.stdin.readline

INF = float('inf')
n, d = map(int, input().split())
short = [list(map(int, input().split())) for _ in range(n)]

def dijkstra():
    # 최단 거리 초기 설정
    weights = [INF] * (d + 1)
    
    # 각 경로의 초기 설정
    edges = [[] for _ in range(d + 1)]
    for i in range(d):
        edges[i].append([i + 1, 1]) 
        
    # 입력받은 지름길 추가
    for li in short:
        if li[1] > d:
            continue
        edges[li[0]].append([li[1], li[2]])
    
    # dijkstra 알고리즘    
    pq = []
    heapq.heappush(pq, [0, 0])
    weights[0] = 0
    
    while pq:
        src, cost = heapq.heappop(pq)
        
        if weights[src] < cost:
            continue
        
        for edge in edges[src]:
            if weights[edge[0]] > weights[src] + edge[1]:
                weights[edge[0]] = weights[src] + edge[1]
                heapq.heappush(pq, edge)
        
    return weights[d]

def solve():
    sorted_short = sorted(short, key = lambda x : x[1])
    dp = list(range(d + 1))
    
    for li in sorted_short:
        src, des, cost = li
        if des > d:
            continue
        
        dp[des] = min(dp[des], dp[src] + cost)
        
        for j in range(des + 1, d + 1):
            dp[j] = min(dp[j], dp[j - 1] + 1)
    
    print(dijkstra())
    # print(dp[d])
    

if __name__ == "__main__":
    solve()