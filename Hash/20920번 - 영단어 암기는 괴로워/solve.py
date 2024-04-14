import sys

input=sys.stdin.readline

eng=dict()

n,m=map(int,input().split())
for i in range(n):
    word=input().rstrip()
    if word not in eng:
        eng[word]=1
    else:
        eng[word]=eng[word]+1

eng={key:value for key,value in eng.items() if len(key)>=m}

eng=sorted(eng.items(),key=lambda x: (-x[1],-len(x[0]),x[0]))

for i in eng:
    print(i[0])
