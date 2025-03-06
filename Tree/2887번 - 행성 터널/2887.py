import sys

input = sys.stdin.readline

n = int(input())
X = []
Y = []
Z = []
parents = list(range(n))
for i in range(n):
    x, y, z = map(int, input().split())
    X.append([x, i])
    Y.append([y, i])
    Z.append([z, i])

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
    sorted_X = sorted(X)
    sorted_Y = sorted(Y)
    sorted_Z = sorted(Z)
    arr = []
    
    for i in range(n - 1):
        arr.append([sorted_X[i+1][0] - sorted_X[i][0], sorted_X[i][1], sorted_X[i+1][1]])
        arr.append([sorted_Y[i+1][0] - sorted_Y[i][0], sorted_Y[i][1], sorted_Y[i+1][1]])
        arr.append([sorted_Z[i+1][0] - sorted_Z[i][0], sorted_Z[i][1], sorted_Z[i+1][1]])
    
    arr.sort(key=lambda x:x[0])
    
    edge_cnt = 0
    min_weight = 0
    for el in arr:
        weight = el[0]
        a = el[1]
        b = el[2]
        
        if Find(a) == Find(b):
            continue
        Union(a, b)
        
        min_weight += weight
        edge_cnt += 1
        if edge_cnt == n - 1:
            break
    
    print(min_weight)

if __name__ == '__main__':
    solve()