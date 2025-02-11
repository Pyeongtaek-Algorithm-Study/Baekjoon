import sys

input = sys.stdin.readline

class testCase():
    def __init__(self, a, b, p):
        self._a = a
        self._b = b
        self._p = p
        
    def lca(self):
        vis = [False] * len(self._p)
        vis[self._a] = True
        
        while self._a != self._p[self._a]:
            self._a = self._p[self._a]
            vis[self._a] = True
        while not vis[self._b]:
            self._b = self._p[self._b]
            
        return self._b

def solve():
    tc = int(input())
    for _ in range(tc):
        n = int(input())
        parents = list(range(n + 1))
        
        for _ in range(n - 1):
            a, b = map(int, input().split())
            parents[b] = a;
        
        fd_a, fd_b = map(int, input().split())
        print(testCase(fd_a, fd_b, parents).lca())
    
if __name__ == '__main__':
    solve()