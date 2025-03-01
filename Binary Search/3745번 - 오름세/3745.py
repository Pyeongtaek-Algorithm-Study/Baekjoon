import sys

input = sys.stdin.readline

def binary_search(aes: list, k: int) -> int:
    l: int = 0
    r: int = len(aes) - 1
    mid: int = r
    
    while l < r:
        mid = (l + r) // 2
        
        if aes[mid] < k:
            l = mid + 1
        else:
            r = mid
    
    return r
            

def solve():
    n: int = int(input())
    stocks: list = list(map(int, input().split()))
    aes_list: list = [stocks[0]]
    
    for i in range(1, n):
        if aes_list[-1] < stocks[i]:
            aes_list.append(stocks[i])
            continue
        idx: int = binary_search(aes_list, stocks[i])
        aes_list[idx] = stocks[i]
    
    print(len(aes_list))

if __name__ == '__main__':
    while True:
        try:
            solve()
        except:
            break