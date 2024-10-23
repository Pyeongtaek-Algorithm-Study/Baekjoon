import sys
import heapq

input = sys.stdin.readline

n = int(input())
min_q = []

for _ in range(n):
    x = int(input())
    if x == 0:
        if len(min_q) == 0:
            print(0)
        else:
            print(heapq.heappop(min_q))
    else:
        heapq.heappush(min_q, x)
        