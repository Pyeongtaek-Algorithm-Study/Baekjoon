from collections import deque
import sys

N, K = map(int, sys.stdin.readline().split())
lst = [int(input()) for i in range(N)]
q = deque([0])
c=0
v = {0: 1}
while q:
    n = q.popleft()
    if lst[n] == K:
        print(v[n])
        c=0
        break
    else:
        c=-1
    if lst[n] not in v:
        v[lst[n]] = v[n] + 1
        q.append(lst[n])
if c!=0:
    print(c)
