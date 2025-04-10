import sys

input = sys.stdin.readline

def solve(n, heights):
    v = [0] * n
    
    for i in range(n):
        for j in range(n):
            # i번째의 값이 0이 되어 들어가야하면서 해당 번째에 사람이 없는 경우
            if heights[i] == 0 and v[j] == 0:
                v[j] = i + 1
                break
            
            # 앞 쪽의 빈 칸에 뒷 순서 사람을 세우면은 자신보다 큰 사람이 있다는 것
            # 따라서, 앞 쪽에서 비어있는 칸을 건너뜀
            if v[j] == 0:
                heights[i] -= 1
    
    print(*v)
            

if __name__ == '__main__':
    n = int(input())
    heights = list(map(int, input().split()))
    solve(n, heights)