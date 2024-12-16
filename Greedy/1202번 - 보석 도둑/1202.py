import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())
gem = []
bag = []
for _ in range(n):
    m, v = map(int, input().split())
    gem.append([m, v])
for _ in range(k):
    bag.append(int(input()))
    
def solve():
    gem.sort()
    bag.sort()
    
    ans = idx = 0
    pq = []
    
    for i in range(k):
        while idx < n and bag[i] >= gem[idx][0]:
            heapq.heappush(pq, (-gem[idx][1], gem[idx][1]))
            idx += 1
        if pq:
            ans += heapq.heappop(pq)[1]
            
    print(ans)

if __name__ == '__main__':
    solve()