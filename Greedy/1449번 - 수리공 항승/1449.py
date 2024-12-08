import sys

input = sys.stdin.readline

n, l = map(int, input().split())
pipe = list(map(int, input().split()))

def solve():
    pipe.sort()
    tape, tape_len = 0, 0
    
    for i in pipe:
        if tape_len < i:
            tape_len = i + l - 1
            tape += 1
    
    print(tape)

if __name__ == '__main__':
    solve()