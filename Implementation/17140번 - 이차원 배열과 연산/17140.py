# 17140: 이차원 배열과 연산
import sys

input = sys.stdin.readline

MAX = 101
r, c, k = map(int, input().split())
arr = [list(0 for _ in range(MAX)) for _ in range(MAX)]
for i in range(3):
    arr[i][0], arr[i][1], arr[i][2] = map(int, input().split())

def change(fir, se, is_row):
    max_len = 0
    for i in range(fir):
        num_cnt = list([0] * MAX)
        bucket = []
        for j in range(se):
            if is_row:
                num_cnt[arr[i][j]] += 1
            else:
                num_cnt[arr[j][i]] += 1
        
        for n in range(1, MAX):
            if num_cnt[n] > 0:
                bucket.append([num_cnt[n], n])

        bucket.sort()
        
        for j in range(se):
            if is_row:
                arr[i][j] = 0
            else:
                arr[j][i] = 0
        
        idx = 0
        bucket_len = len(bucket)
        max_len = max(max_len, bucket_len * 2)
        for j in range(bucket_len):
            if is_row:
                arr[i][idx] = bucket[j][1]
                idx += 1
                arr[i][idx] = bucket[j][0]
                idx += 1
            else:
                arr[idx][i] = bucket[j][1]
                idx += 1
                arr[idx][i] = bucket[j][0]
                idx += 1
    
    return max_len


def solve():
    h = w = 3
    t = 0
    
    while(1):
        if arr[r - 1][c - 1] == k:
            print(t)
            break
        if t > 100:
            print(-1)
            break
        
        if h >= w:
            w = change(h, w, True)
        else:
            h = change(w, h, False)
        t += 1


if __name__ == '__main__':
    solve()