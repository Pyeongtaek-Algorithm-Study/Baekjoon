import sys
from collections import deque

input = sys.stdin.readline

LIM = 27

degree = [0] * LIM
time = [0] * LIM
project = [[] for _ in range(LIM)]

while True:
    try:
        tmp = input().split()
        alpha = ord(tmp[0]) - ord('A')
        time[alpha] = int(tmp[1])
        
        if len(tmp) > 2:
            for c in tmp[2]:
                project[ord(c) - ord('A')].append(alpha)
            degree[alpha] = len(tmp[2])
    except:
        break

def solve():
    q = deque()
    min_time = [0] * LIM
    
    for i in range(LIM):
        if degree[i] == 0 and time[i]:
            q.append(i)
            min_time[i] = time[i]
    
    while q:
        now = q.popleft()
        
        for nxt in project[now]:
            min_time[nxt] = max(min_time[nxt], min_time[now] + time[nxt])
            
            degree[nxt] -= 1
            if degree[nxt] == 0:
                q.append(nxt)
                
    print(max(min_time))
        

if __name__ == '__main__':
    solve()