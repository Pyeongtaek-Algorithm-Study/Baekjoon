import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n, m = map(int, input().split())
parents = list(range(n))
    
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
    for i in range(1, m + 1):
        a, b = map(int, input().split())
        if Find(a) == Find(b):
            print(i)
            return
        Union(a, b)
    print(0)

if __name__ == '__main__':
    solve()