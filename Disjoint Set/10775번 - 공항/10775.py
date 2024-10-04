import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**7)

g = int(input())
p = int(input())
airplane = []
parents = [i for i in range(g + 1)]
for _ in range(p):
    airplane.append(int(input()))
    
def find(x):
    if parents[x] != x: 
        parents[x] = find(parents[x])
    return parents[x]
    
def union(x, y):
    x = find(x)
    y = find(y)
    if x != y:
        parents[y] = x
    
def solve():
    ans = 0
    
    for air in airplane:
        dock = find(air)
        if dock == 0: 
            break
        
        union(dock - 1, dock)
        ans += 1
    
    print(ans)
        
if __name__ == '__main__':
    solve()