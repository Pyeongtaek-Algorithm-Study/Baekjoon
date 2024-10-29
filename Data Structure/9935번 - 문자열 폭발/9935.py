import sys
from collections import deque

input = sys.stdin.readline

str = str(input().rstrip())
bomb = input().rstrip()

stack = []
bomb_len = len(bomb)

for i in range(len(str)):
    stack.append(str[i])
    if ''.join(stack[-bomb_len:]) == bomb:
        for _ in range(bomb_len):
            stack.pop()

res = ''.join(stack)

    
print(res if res else "FRULA")
        