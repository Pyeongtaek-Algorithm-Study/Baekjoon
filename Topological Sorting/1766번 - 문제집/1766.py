# 1766번: 문제집
import sys
import heapq as hq

input = sys.stdin.readline

n, m = map(int, input().split())
degree = [0 for _ in range(n + 1)]
pre = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    pre[a].append(b)
    degree[b] += 1

def solve():
    heap = [i for i in range(1, n + 1) if degree[i] == 0]

    while heap:
        now = hq.heappop(heap)
        print(now, end=' ')
        for el in pre[now]:
            degree[el] -= 1
            if degree[el] <= 0: 
                hq.heappush(heap, el)

if __name__ == '__main__':
    solve()