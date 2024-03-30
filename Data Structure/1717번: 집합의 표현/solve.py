import sys

input = sys.stdin.readline

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])  # 경로 압축
    return parent[a]

def union(a, b):
    parent_a = find(a)
    parent_b = find(b)
    if parent_a != parent_b:
        parent[parent_b] = parent_a

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]  # 1부터 인덱스 시작

arr = [list(map(int, input().split())) for _ in range(m)]

for i in arr:
    if i[0] == 0:
        union(i[1], i[2])
    else:
        if find(i[1]) != find(i[2]):
            print("NO")
        else:
            print("YES")
