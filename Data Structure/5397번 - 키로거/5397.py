import sys

input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    st = input().rstrip()
    left, right = [], []
    for c in st:
        if c == '<':
            if left:
                right.append(left.pop())
                
        elif c == '>':
            if right:
                left.append(right.pop())
                
        elif c == '-':
            if left:
                left.pop()
            
        else:
            left.append(c)
        
    print(''.join(left) + ''.join(reversed(right)))