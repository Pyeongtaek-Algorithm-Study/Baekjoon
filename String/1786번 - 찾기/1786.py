import sys

input = sys.stdin.readline

s = input().rstrip()
p = input().rstrip()

def get_pi(p):
    l = len(p)
    table = list(0 for _ in range(l + 1))
    j = 0
    
    for i in range(1, l):
        while j > 0 and p[i] != p[j]:
            j = table[j-1]
        if p[i] == p[j]:
            j += 1
            table[i] = j
            
    return table

def kmp(s, p):
    ans = []
    table = get_pi(p)
    s_len, p_len, j = len(s), len(p), 0
    for i in range(s_len):
        while j > 0 and s[i] != p[j]:
            j = table[j-1]
        if s[i] == p[j]:
            if j == p_len - 1:
                ans.append(i - p_len + 2)
                j = table[j]
            else:
                j += 1
    
    return ans
    
def solve():
    mattched = kmp(s, p)
    
    print(len(mattched))
    for i in mattched:
        print(i, end=' ')

if __name__ == '__main__':
    solve()