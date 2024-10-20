import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
parents = list(i for i in range(n + 1))

def find(x):
    if x != parents[x]: 
      parents[x] = find(parents[x])  
    return parents[x]

def union(x, y):
    x = find(x)
    y = find(y)
    if x > y: 
        parents[x] = y
    else: 
        parents[y] = x
    

def solve():
    for i in range(1, n + 1):
        num = list(map(int, input().split()))
        for j in range(1, n + 1):
            if(num[j-1] == 1): 
                union(i, j)
    
    plan = list(map(int, input().split()))
    flag = True
    for i in range(len(plan) - 1):
        if(parents[plan[i]] != parents[plan[i + 1]]):
            flag = False
            break
    print("YES" if flag else "NO")

if __name__ == '__main__':
    solve()