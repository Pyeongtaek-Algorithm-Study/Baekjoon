import sys

input = sys.stdin.readline

INF = 10**7

n = int(input())
m = int(input())
bus = list([INF] * (n + 1) for _ in range(n + 1))
path = list([[] for _ in range(n + 1)] for _ in range(n + 1))
for _ in range(m):
    a, b, c = map(int, input().split())
    bus[a][b] = min(bus[a][b], c)
    path[a][b] = [b]
    
def print_ans():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(bus[i][j] if bus[i][j] != INF else 0, end = ' ')
        print()
    
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if(bus[i][j] == INF):
                print(0)
                continue
            
            path[i][j] = [i] + path[i][j]
            print(len(path[i][j]), end = ' ')
            print(*path[i][j])
    

def solve():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if i == j:
                    continue
                if (bus[i][k] and bus[k][j]) and (bus[i][j] > bus[i][k] + bus[k][j]):
                    bus[i][j] = bus[i][k] + bus[k][j]
                    path[i][j] = path[i][k] + path[k][j]

    print_ans()
                    

if __name__ == '__main__':
    solve()