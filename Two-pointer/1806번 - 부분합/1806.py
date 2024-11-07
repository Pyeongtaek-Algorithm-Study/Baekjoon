import sys

input = sys.stdin.readline

n, s = map(int, input().split())
seq = list(map(int, input().split()))

def solve():
    st = end = 0
    seq_sum = seq[0]
    ans = 1e9
    
    while st <= end <= n - 1:
        if seq_sum < s:
            end += 1
            if end == n: 
                break
            seq_sum += seq[end]
        else:
            ans = min(ans, end - st + 1)
            seq_sum -= seq[st]
            st += 1
    
    print(ans if ans != 1e9 else 0)

if __name__ == '__main__':
    solve()