import sys

input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)]

def solve():
    push_pop = []
    stack = []
    cur = 1
    
    for n in nums:
        while cur <= n:
            stack.append(cur)
            push_pop.append("+")
            cur += 1
        
        if stack[-1] == n:
            push_pop.append("-")
            stack.pop()
        else:
            print("NO")
            sys.exit()
    
    print(*push_pop, sep='\n')

if __name__ == '__main__':
    solve()