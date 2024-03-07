# 14888번: 연산자
### 문제해설
* 이 문제는 N개의 수와 N-1개의 연산자를 이용하여 만들 수 있는 수식의 결과 중에서 최대값과 최소값을 찾는 문제입니다. 주어진 수의 순서는 바꾸면 안 되며, 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로 이루어져 있습니다. 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행되며, 나눗셈은 정수 나눗셈으로 몫만 취합니다. 주어진 수와 연산자를 활용하여 가능한 모든 수식을 생성하고, <br>
각 수식의 결과를 계산하여 최대값과 최소값을 구해야 합니다.사용자 수를 찾는 것이 목표입니다.
* * *
### 풀이과정
사용자로부터 수의 개수 N, 수열 num, 그리고 덧셈, 뺄셈, 곱셈, 나눗셈 연산자의 개수 op를 입력받습니다.<br>
maximum: 최대값을 저장하는 변수로, 초기값은 음의 무한대로 설정합니다. <br>
minimum: 최소값을 저장하는 변수로, 초기값은 양의 무한대로 설정합니다. <br>
<pre>
  <code>
    maximum = -1e9
    minimum = 1e9
  </code>
</pre>
dfs함수를 재귀로 부릅니다.
부를때 부르는 횟수가 n이되면 값을 구해줘야 합니다.<br>
따라서 함수를 호출할때 depth 변수에 1을 더해 횟수를 세어줍니다.<br>
depth==n이 되면 초기화된 maximum과 minimum을 비교 연산하여 값을 넣어줍니다.<br>
if plus, minus, multiply,divide 하는 이유는 조건문에 숫자가 있다면 조건문을 실행시키기 때문입니다.<br>
즉 plus에 수가 들어가 있다면 더하기 연산을 해주고 남은 배열들을 dfs에 다시 호출해줍니다.<br>

<dfs함수>
<pre>
  <code>
  def dfs(depth, total, plus, minus, multiply, divide):
    global maximum, minimum
    if depth == N:
        maximum = max(total, maximum)
        minimum = min(total, minimum)
        return

    if plus:
        dfs(depth + 1, total + num[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, total - num[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, total * num[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(total / num[depth]), plus, minus, multiply, divide)
  </code>
</pre>
### 코드
<pre>
<code>
import sys

input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
op = list(map(int, input().split()))  # +, -, *, //

maximum = -1e9
minimum = 1e9


def dfs(depth, total, plus, minus, multiply, divide):
    global maximum, minimum
    if depth == N:
        maximum = max(total, maximum)
        minimum = min(total, minimum)
        return

    if plus:
        dfs(depth + 1, total + num[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, total - num[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, total * num[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(total / num[depth]), plus, minus, multiply, divide - 1)


dfs(1, num[0], op[0], op[1], op[2], op[3])
print(maximum)
print(minimum)
</code>
</pre>
### 링크
* <https://www.acmicpc.net/problem/14888>
