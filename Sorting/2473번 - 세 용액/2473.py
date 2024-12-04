import sys

input = sys.stdin.readline

n = int(input())
sol = list(map(int, input().split()))

def solve():
    sol.sort()
    
    comp = 1e18
    elements = [0, 0, 0]
    
    for i in range(n - 2):
        l, r = i + 1, n - 1
        while l < r:
            sum = sol[i] + sol[l] + sol[r]
            
            if comp > abs(sum):
                comp = abs(sum)
                elements[0], elements[1], elements[2] = sol[i], sol[l], sol[r]
            
            if sum < 0: l += 1
            else: r -= 1
    
    print(*elements)        

if __name__ == '__main__':
    solve()