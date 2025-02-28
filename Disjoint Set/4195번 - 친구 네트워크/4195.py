import sys

input = sys.stdin.readline

def Find(a):
    if a != parent[a]:
        parent[a] = Find(parent[a])
    return parent[a]
    
def Union(a, b):
    a = Find(a)
    b = Find(b)
    if a != b:
        parent[b] = a
        people[a] += people[b]
        
    print(people[a])

tc = int(input())
for _ in range(tc):
    n = int(input())
    parent = dict()
    people = dict()
    
    for _ in range(n):
        a, b = input().split()
        
        if not a in parent:
            parent[a] = a
            people[a] = 1
            
        if not b in parent:
            parent[b] = b
            people[b] = 1
        
        Union(a, b)