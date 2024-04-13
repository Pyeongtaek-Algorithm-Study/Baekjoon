### 문제 제목
25418번: 정수 a를 k로 만들기
* * *
### 링크
* <https://www.acmicpc.net/problem/25418>
* * *
### 문제 해석
* * *
연산 1: 정수 A에 1을 더한다.
연산 2: 정수 A에 2를 곱한다.
연산 1과 2를 사용하여 a에서 k로 될 수 있는 최소 연산을 구해야 한다.
### 풀이
* * *
최소 연산 횟수 이므로 BFS(너비 우선 탐색) 알고리즘을 이용해야한다.<br>
BFS를 쓰는 이유는 BFS는 노드에서 바로 인접한 노드로 이동할 수 있다. 즉 가장 가까운 노드를 구하므로
최단의 길이를 구할 수 있다.<br>
예로, 7 77이면, 7이라는 노드에 8, 14라는 모두 list에 넣어주고, 그 list를 반복문을 돌려 큐에 넣어준다.<br>
8이랑 14가 77이 아니면 visit에 넣어주고, 9,16,15,28를 큐에 넣어준다.<br>
77이 나올때까지 큐에 넣어 주다가 반복된 수가 있거나 77보다 크면 q와 visit에 안 넣어줘도 된다.<br>
넣어줄때마다 c에 1씩 더해준다.<br>
77이 나오면 그때 최소 연산 횟수를 구해주고 return해주면 된다.

<pre>
<code>
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
</code>
</pre>

dp로도 활용이 가능하다.
구글링을 해봤더니 최소 연산 횟수 이므로 목표값에서 2로 나누는게 더 횟수가 적어지니, 2로 나눌때 나머지가<br>
0이거나, 2*a<k면 K를 2로 나누면 된다.
그게 아니면 계속 -1을 해주고, 연산 횟수를 세어주면 된다.

<pre>
<code>
a,k=map(int,input().split())
count = 0

while True:
    if a == k:
        print(count)
        break
    if k % 2 == 0 and k >= a*2:
        k = int(k/2)
    else:
        k = k - 1
    count+=1
</code>
</pre>
