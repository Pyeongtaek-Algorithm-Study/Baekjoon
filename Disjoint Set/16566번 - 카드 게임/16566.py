import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
m_s = list(map(int, input().split()))
ch_s = list(map(int, input().split()))
parents = list(range(n + 1))

def Find(x):
    if x != parents[x]:
        parents[x] = Find(parents[x])
    return parents[x]
    
def Union(x, y):
    x = Find(x)
    y = Find(y)
    if x != y:
        parents[y] = x
        
def binarySearch(arr, k):
    st = 0
    end = len(arr) - 1
    while st <= end:
        mid = (st + end) // 2
        
        if k < arr[mid]:
            end = mid - 1
        else:
            st = mid + 1
    
    return st

def solve():
    m_s.sort()
    for ch in ch_s:
        idx = Find(binarySearch(m_s, ch))
        print(m_s[idx])
        Union(idx + 1, idx)

if __name__ == '__main__':
    solve()