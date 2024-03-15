# 16938번: 캠프준비
* * *
### 문제해설
문제 갯수 N개가 주어지고, 각 문제별 난이도가 주어진다. 캠프에서 문제들을 내려고 할때<br>
문제는 두문제 이상이어야하며, 문제들의 난이도 합은 L보다 크거나 작고, R보다 작거나 같아야한다.<br>
또한, 문제들 중 가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 x보다 크거나 같아야 한다.
### 풀이과정
문제가 2문제 이상이니, 문제들중 2개씩 뽑는 것부터 실행해줘야하므로 for문에서 (2,n+1)를 해주었다<br>
그러면 문제를 2개부터 전체 문제까지 뽑는 조합들이 다 나오는데<br>
이를 list형식으로 반환하여 그 list를 for문으로 돌려<br>
각 요소들을 구해준다<br>
그리고 그 요소들은 뽑힌 문제들의 난이도 이기 때문에<br>
sum(문제 난이도)가 L보다 크거나 작고, R보다 작거나 같고, MAX(문제 난이도)-MIN(문제 난이도)>=x이면
C변수에 1씩 더해준다.


### 코드
<pre>
<code>
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


print(c)
  
</code>
</pre>

### 링크
<https://www.acmicpc.net/problem/16938>
