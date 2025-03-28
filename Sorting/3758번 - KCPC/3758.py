import sys

input = sys.stdin.readline

def solve(n, k, t, m, logs):
    cnt = [0] * (n + 1)
    last = [0] * (n + 1)
    points = [[0] * (k + 1) for _ in range(n + 1)]
    
    for i in range(len(logs)):
        tid, pid, score = logs[i]
        points[tid][pid] = max(points[tid][pid], score)
        cnt[tid] += 1
        last[tid] = i
    
    rank = []
    for i in range(1, n + 1):
        rank.append([-sum(points[i]), cnt[i], last[i], i])
    
    sorted_rank = sorted(rank)
    print(*[i + 1 for i in range(n) if sorted_rank[i][3] == t])


if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        n, k, t, m = map(int, input().split())
        logs = [list(map(int, input().split())) for _ in range(m)]
        solve(n, k, t, m, logs)