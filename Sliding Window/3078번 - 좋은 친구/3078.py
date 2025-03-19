import sys

input = sys.stdin.readline

n, k = map(int, input().split())
student_name_len = [len(input().rstrip()) for _ in range(n)]

def solve():
    len_cnt = [0] * 21
    ans = 0
    
    for i in range(k + 1):
        len_cnt[student_name_len[i]] += 1
    
    for i in range(n):
        len_cnt[student_name_len[i]] -= 1
        ans += len_cnt[student_name_len[i]]
        
        if (i + k + 1) < n:
            len_cnt[student_name_len[i + k + 1]] += 1
        
    print(ans)


if __name__ == '__main__':
    solve()