import sys

input = sys.stdin.readline

INF = 987654321

v, e = map(int, input().split())
dist = list([INF] * (v + 1) for _ in range(v+1))
for _ in range(e):
    a, b, c = map(int, input().split())
    dist[a][b] = c;

def solve():
    for k in range(1, v + 1):
        for i in range(1, v + 1):
            for j in range(1, v + 1):
                if dist[i][k] > 0 and dist[k][j] > 0:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                    
    city = list(dist[i][i] for i in range(1, v + 1))
    ans = min(city)
    print(ans if ans != INF else -1)

if __name__ == '__main__':
    solve()