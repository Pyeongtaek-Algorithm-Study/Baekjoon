import sys

infix = input().rstrip()

def pri(ch):
    if ch == '(' or ch == ')':
        return 0
    elif ch == '+' or ch == '-':
        return 1
    elif ch == '*' or ch == '/':
        return 2

def solve():
    ans = ''
    stack = []
    
    for c in infix:
        if c == '(':
            stack.append('(')
        elif c == ')':
            t = stack.pop()
            while stack and t != '(':
                ans += t
                t = stack.pop()
        elif c == '+' or c =='-' or c == '*' or c == '/':
            while stack and pri(c) <= pri(stack[-1]):
                ans += stack.pop()
            stack.append(c)
        else:
            ans += c
            
    stack.reverse()
    print(ans + ''.join(stack))


if __name__ == '__main__':
    solve()