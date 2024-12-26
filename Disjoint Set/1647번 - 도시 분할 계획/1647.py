import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n, m = map(int, input().split())
edges = sorted([tuple(map(int, input().split())) for _ in range(m)], key=lambda x : x[2])
parents = list(range(n + 1))

def find(a):
    if parents[a] == a: 
        return a
    parents[a] = find(parents[a])
    return parents[a] 

def union(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        parents[b] = a

def solve():
    weight = []

    for a, b, c in edges:
        if find(a) != find(b):
            union(a, b)
            weight.append(c)

    print(sum(weight[:-1]))

if __name__ == '__main__':
    solve()