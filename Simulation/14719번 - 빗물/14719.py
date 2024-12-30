import sys

input = sys.stdin.readline

h, w = map(int, input().split())
water = list(map(int, input().split()))

total = 0

for i in range(w):
    left = 0
    right = 0
    for _ in range(0, i):
        left = max(left, water[_])
    for _ in range(i + 1, w):
        right = max(right, water[_])
    if left != 0 and right != 0 and (min(left, right) > water[i]):
        cnt = min(left, right) - water[i]
        total += cnt
        
print(total)