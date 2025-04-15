import sys

input = sys.stdin.readline

x, y, w, s = map(int, input().split())

def solve():
    ans = 0
    
    # 도착 지점의 가로 세로 중 더 작은 값을 기준으로 대각방향 좌표
    # 대각선 가는 것을 가로 세로 2번 이동과 바로 대각선 소요 시간 비교
    cross = min(x, y)
    cross_sw = min(w * 2, s)
    
    # 대각선 건너기
    ans += cross * cross_sw
    
    # 나머지 직선 거리 건너기
    # 대각 vs 한 블록 거리를 비교해서 더 작은 값으로 이동
    # 남은 직선 거리가 짝수일 땐, 더 작은 값으로 남은 거리까지 가기
    # 홀수 일 땐, -1을 한 짝수 거리까지 간 후, 한 블록 가기
    diff = abs(x - y)
    sw = min(w, s)
    if diff % 2 == 0:
        ans += diff * sw
    else :
        ans += (diff - 1) * sw + w
    # ans += (diff - 1) * sw
    # ans += (sw if diff % 2 == 0 else w)
    
    print(ans)

if __name__ == '__main__':
    solve()