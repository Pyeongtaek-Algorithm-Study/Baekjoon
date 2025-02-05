import sys

input = sys.stdin.readline

INF = 10**7

def test_case(n, paths):
    min_cost = [INF] * (n + 1)
    min_cost[1] = 0
    
    for _ in range(n):
        for path in paths:
            st, end, cost = path[0], path[1], path[2]
            
            if min_cost[end] > min_cost[st] + cost:
                min_cost[end] = min_cost[st] + cost
    
    for path in paths:
        st, end, cost = path[0], path[1], path[2]
        
        if min_cost[end] > min_cost[st] + cost:
            return "YES"
            
    return "NO"
    

def solve():
    tc = int(input())
    
    while tc > 0:
        n, m, w = map(int, input().split())
        edges = []
        for _ in range(m):
            a, b, c = map(int, input().split())
            edges.append([a, b, c])
            edges.append([b, a, c])
        for _ in range(w):
            edges.append(list(map(lambda x: -x[1] if x[0] == 2 else x[1], 
                                  enumerate(map(int, input().split())))))
                                  
        print(test_case(n, edges))
        tc -= 1

if __name__ == '__main__':
    solve()