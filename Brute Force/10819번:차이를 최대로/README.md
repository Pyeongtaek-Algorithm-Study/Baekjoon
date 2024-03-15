# 10819번: 차이를 최대로
### 문제해설
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
* * *
### 풀이과정
dfs로 구현을 하려다가 너무 복잡해서 순열 라이브러리를 이용하였다.<br>
순열을 구해주는 permutation함수를 for문안에 넣어줘서, 순열이 나올때마다 그 순열대로 식이 실행되게 해주었다.<br>
m=0으로 처음에 초기화를 해준다음 m보다 식의 값이 크다면 교환해주었다.<br>
<pre>
  <code>
import sys
from itertools import permutations
input=sys.stdin.readline
m = 0
for a in permutations(map(int, input().split())):
    s = sum([abs(a[i] - a[i-1])
             for i in range(len(a)-1)])
    if s > m:
        m = s
print(m)
  </code>
</pre>
### dfs풀이
<pre>
  <code>
    import sys

def dfs(depth):
    if depth == N:
        result.append(sum(abs(explore[i] - explore[i + 1]) for i in range(N - 1)))
        return
    for i in range(N):
        if visited[i]:
            continue
        explore.append(A[i])
        visited[i] = 1
        dfs(depth + 1)
        visited[i] = 0
        explore.pop()

input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))

visited = [0] * N
result, explore = [], []
dfs(0)
print(max(result))

  </code>
</pre>
### 코드 설명
dfs문을 이용해주는데 depth라는 깊이 변수가 순열의 길이가 되면 result에 식의 값을 넣어줘야된다.<br>
따라서 dfs문으로 depth를 이용해 순열을 만들어주면 되는데, for문으로 n까지의 수를 반복문으로 돌려주고, <br>
i번째 수가 visit에 있다면 넘어가주고, 없다면 visit에 넣어주고 dfs문을 돌린다.<br>
만약 1번째 수가 visit에 없다면 visit[1]=1이되고, 다시dfs문을 실행해주므로,<br>
다시 또 반복문이 실행되는데 이때 1은 이미 visit에 있기 때문에 continue하고 다음수인 2번째수로 순열을 만들어준다.<br>
간단히 설명을 해주면, 재귀가 될때마다 n번째의 수들을 반복문으로 탐색해주고, visit에 없는 수들을 순열에 넣어주면 된다<br>
또한 재귀로 부른 함수로부터 return이 되면 그 자리는 다시 0으로 만들어줘야된다.

### 링크
* <https://www.acmicpc.net/problem/10819>
