import sys

input = sys.stdin.readline

st = input().rstrip()

def solve():
    a_cnt, ans = 0, 1000
    for c in st:
        if c == 'a':
            a_cnt += 1
    
    l = len(st)
    for i in range(l):
        b_cnt = 0
        for j in range(a_cnt):
            if st[(i + j) % l] == 'b':
                b_cnt += 1
        ans = min(ans, b_cnt)
    
    print(ans)

if __name__ == '__main__':
    solve()