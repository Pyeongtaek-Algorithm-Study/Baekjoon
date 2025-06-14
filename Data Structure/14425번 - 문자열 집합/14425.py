import sys

input = sys.stdin.readline

def solve(set_str, ins_str):
    ans = 0
    for ins in ins_str:
        if ins in set_str:
            ans += 1
    
    print(ans)

if __name__ == '__main__':
    n, m = map(int, input().split())
    set_str = set([input().rstrip() for _ in range(n)])
    ins_str = [input().rstrip() for _ in range(m)]
    solve(set_str, ins_str)