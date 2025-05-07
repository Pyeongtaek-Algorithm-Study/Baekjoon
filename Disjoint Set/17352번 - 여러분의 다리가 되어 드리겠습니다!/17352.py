import sys
sys.setrecursionlimit(10**7)

input = sys.stdin.readline

n = int(input())
bridges = [tuple(map(int, input().split())) for _ in range(n - 2)]
parents = list(range(n + 1))

def Find(a):
    if a != parents[a]:
        parents[a] = Find(parents[a])
    return parents[a]

def Union(a, b):
    a = Find(a)
    b = Find(b)
    if a != b:
        parents[b] = a

def solve():
    
    for a, b in bridges:
        Union(a, b)
    
    for i in range(2, n + 1):
        if Find(1) != Find(i):
            print(f"1 {i}")
            break

if __name__ == '__main__':
    solve()