import sys
from itertools import combinations

#문제 난이도의 합>=L
#문제 난이도의 합<=R
#가장 어려운 문제의 난이도- 가장 쉬운 문제의 난이도>=x
input=sys.stdin.readline

n,l,r,x=map(int,input().split())
arr=list(map(int,input().split()))
c=0
for i in range(2,n+1):
    question=list(combinations(arr,i))
    for j in question:
        if l<=sum(j)<=r and max(j)-min(j)>=x:
            c+=1
            
    
