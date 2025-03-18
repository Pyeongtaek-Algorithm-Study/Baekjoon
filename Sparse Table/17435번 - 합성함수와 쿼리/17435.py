import sys

input = sys.stdin.readline

m = int(input())
num = [[0] + list(map(int, input().split()))]

def sparse_array(log):
    for j in range(1, log):
        temp_list = [0]
        for i in range(1, m + 1):
            temp_list.append(num[j-1][num[j-1][i]])
        num.append(temp_list)
    
def solve():
    sparse_array(20)
    
    q = int(input())
    for _ in range(q):
        n, x = map(int, input().split())
        i = 0
        while n:
            if n & 1:
                x = num[i][x]
            n >>= 1
            i += 1
        print(x)
            
if __name__ == '__main__':
    solve()