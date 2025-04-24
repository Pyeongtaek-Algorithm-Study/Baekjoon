import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
networks = [list(map(int, input().split())) for _ in range(m)]
sorted_networks = sorted(networks, key = lambda x : x[2])
parents = list(range(n + 1))

def Find(x):
    if x != parents[x]:
        parents[x] = Find(parents[x])
    
    return parents[x]
    
def Union(a, b):
    a = Find(a)
    b = Find(b)
    if a != b:
        parents[b] = a

def solve():
    weight = 0
    cnt = 0
    for a, b, c in sorted_networks:
        if Find(a) == Find(b):
            continue
        
        Union(a, b)
        weight += c
        cnt += 1
        
        if cnt == n - 1:
            break
        
    print(weight)

if __name__ == '__main__':
    solve()