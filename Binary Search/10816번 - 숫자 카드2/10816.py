import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
cards = list(map(int, input().split()))
m = int(input())
amounts = list(map(int, input().split()))

def solve():
    dd = defaultdict(int)
    
    for card in cards:
        dd[card] += 1
    
    for amount in amounts:
        print(dd.get(amount, 0), end = ' ')
    

if __name__ == '__main__':
    solve()