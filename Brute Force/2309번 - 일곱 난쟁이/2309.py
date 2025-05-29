import sys

input = sys.stdin.readline

def solve(dwarf):
    # sorted_dwarf = sorted(dwarf)
    
    # 9명의 난쟁이의 키는 100보다 크므로, 이 중 2명이 100 외의 오차를 만들어 냄.
    total = sum(dwarf) - 100
    
    for i in range(9):
        for j in range(i + 1, 9):
            if dwarf[i] + dwarf[j] == total:
                ans = [dwarf[d] for d in range(9) if d != i and d != j]
                print(*sorted(ans), sep = '\n')
                
                return

if __name__ == '__main__':
    dwarf = [int(input()) for _ in range(9)]
    solve(dwarf)