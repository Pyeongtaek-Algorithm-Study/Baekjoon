import sys
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())
arr = [[] for _ in range(1001)]
for _ in range(n - 1):
    a, b, w = map(int, input().split())
    arr[a].append([b, w])
    arr[b].append([a, w])
    

def dfs(st, end, weight, vis):
    vis[st] = 1
    if st == end:
        print(weight)
        return
    
    for el in arr[st]:
        n_st = el[0]
        n_weight = el[1] + weight
        if not vis[n_st]:
            dfs(n_st, end, n_weight, vis)


def solve():
    for _ in range(m):
        a, b = map(int, input().split())
        dfs(a, b, 0, [0] * (n+1))


if __name__ == '__main__':
    solve()