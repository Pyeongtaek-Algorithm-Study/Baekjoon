import sys

input = sys.stdin.readline

n = int(input())
arr = [0] + [int(input()) for _ in range(n)]
res = []

def recursive(st, val, visited):
    if visited[val]:
        if st == val:
            res.append(st)
        return
    visited[val] = True
    recursive(st, arr[val], visited)

def solve():
    for i in range(1, n + 1):
        vis = [False for _ in range(n + 1)]
        vis[i] = True
        recursive(i, arr[i], vis)
    
    print(len(res))
    for r in res:
        print(r)

if __name__ == '__main__':
    solve()