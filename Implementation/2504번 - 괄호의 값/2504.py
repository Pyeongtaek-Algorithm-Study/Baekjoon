import sys

input = sys.stdin.readline

pare = input().rstrip()
st = []

def solve():
    ans, tmp = 0, 1
    pre = ' '
    for c in pare:
        if c == '(':
            st.append(c)
            tmp *= 2
        elif c == '[':
            st.append(c)
            tmp *= 3
        elif c == ')':
            if not st or st[-1] == '[':
                ans = 0
                break
            
            st.pop()
            
            if pre == '(':
                ans += tmp
            tmp //= 2
            
        elif c == ']':
            if not st or st[-1] == '(':
                ans = 0
                break
            
            st.pop()
            
            if pre == '[':
                ans += tmp
            tmp //= 3
        
        pre = c
    
    print(ans if not st else 0)

if __name__ == '__main__':
    solve()