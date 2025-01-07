import sys

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

def binary_search(arr, k):
    st = 0
    end = len(arr) - 1
    
    while st < end:
        mid = (st + end) // 2
        if arr[mid] < k:
            st = mid + 1
        else:
            end = mid
    return end

def solve():
    aes = [seq[0]]
    
    for el in seq[1:]:
        if el > aes[-1]:
            aes.append(el)
        else:
            idx = binary_search(aes, el)
            aes[idx] = el
    
    print(len(aes))

if __name__ == '__main__':
    solve()