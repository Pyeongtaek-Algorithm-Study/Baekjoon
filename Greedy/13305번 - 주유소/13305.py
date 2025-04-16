import sys

input = sys.stdin.readline

def solve(n, road, gas_station):
    ans = 0
    
    min_gas = float('inf')
    
    # 마지막 주유소는 도착이므로 계산 X
    for i in range(n - 1):
        min_gas = min(min_gas, gas_station[i])
        ans += road[i] * min_gas
    
    print(ans)

if __name__ == '__main__':
    n = int(input())
    road = list(map(int, input().split()))
    gas_station = list(map(int, input().split()))
    solve(n, road, gas_station)