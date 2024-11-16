import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
seq = [[] for _ in range(n + 1)]
degree = [0 for i in range(n + 1)]
for _ in range(m):
    tmp = list(map(int, input().split()))
    for num in range(1, tmp[0]):
        a = tmp[num]
        b = tmp[num + 1]
        seq[a].append(b)
        degree[b] += 1

def solve():
    q = deque([i for i in range(1, n + 1) if degree[i] == 0])
    ans = []

    while q:
        now = q.popleft()
        ans.append(now)
        for el in seq[now]:
            degree[el] -= 1
            if degree[el] <= 0:
                q.append(el)
    
    if len(ans) == n:
        print(*ans)
    else:
        print(0)

if __name__ == '__main__':
    solve()