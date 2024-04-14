from collections import deque
a,k=map(int,input().split())
q=deque([a])
v={a:0}
while q:
    c=q.popleft()
    if c==k: break
    for x in [2*c,c+1]:
        if x in v or x>k: continue
        v[x]=v[c]+1
        q+=[x]
print(v[k])
