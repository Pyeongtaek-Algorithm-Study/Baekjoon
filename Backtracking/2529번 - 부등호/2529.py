import sys

input = sys.stdin.readline

n = int(input())
comp = str(input().rstrip())
min_res = "987654321"
max_res = "0"

def recursive(num_str, num_chk, cnt):
    global min_res
    global max_res 
    
    if cnt == n:
        min_res = min(min_res, num_str)
        max_res = max(max_res, num_str)
        return
    
    for i in range(0, 10):
        if num_chk[i]: continue
        if comp[cnt*2] == '>' and int(num_str[-1]) > i:
            num_str += str(i)
            num_chk[i] = True
            recursive(num_str, num_chk, cnt + 1)
            num_str = num_str[:-1]
            num_chk[i] = False
    
        if comp[cnt*2] == '<' and int(num_str[-1]) < i:
            num_str += str(i)
            num_chk[i] = True
            recursive(num_str, num_chk, cnt + 1)
            num_str = num_str[:-1]
            num_chk[i] = False
    
def solve():
    for i in range(0, 10):
        chk = [False for _ in range(10)]
        chk[i] = True
        recursive(str(i), chk, 0)
        
    print(max_res)
    print(min_res)


if __name__ == '__main__':
    solve()