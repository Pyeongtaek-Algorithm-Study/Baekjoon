import sys
from math import comb
input=sys.stdin.readline
n,m,k=map(int,input().split())
result=[]
if comb(n+m,n)<k:
    print(-1)

else:
    while n>0 and m>0:
        cb=comb(n+m+1,n-1)
        if cb>=k:
            result.append('a')
            n=n-1

        else:
            result.append('z')
            m=m-1
            k=-cb

    result.extend(['a']*n)
    result.extend(['z']*m)

    print(''.join(result))

