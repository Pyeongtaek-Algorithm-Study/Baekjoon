import sys
from itertools import permutations
input=sys.stdin.readline
m = 0
for a in permutations(map(int, input().split())):
    s = sum([abs(a[i] - a[i-1])
             for i in range(len(a)-1)])
    if s > m:
        m = s
print(m)
