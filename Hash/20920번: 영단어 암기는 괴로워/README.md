# 20920번: 영단어 암기는 괴로워
### 문제해설
* 화은이는 이번 영어 시험에서 틀린 문제를 바탕으로 영어 단어 암기를 하려고 한다.<br>
그 과정에서 효율적으로 영어 단어를 외우기 위해 영어 단어장을 만들려 하고 있다.<br>
화은이가 만들고자 하는 단어장의 단어 순서는 다음과 같은 우선순위를 차례로 적용하여 만들어진다.<br>
  1.자주 나오는 단어일수록 앞에 배치한다.<br>
  2.해당 단어의 길이가 길수록 앞에 배치한다.<br>
  3.알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다<br>
 
$M$보다 짧은 길이의 단어의 경우 읽는 것만으로도 외울 수 있기 때문에 길이가 
$M$이상인 단어들만 외운다고 한다. 화은이가 괴로운 영단어 암기를 효율적으로 할 수 있도록 단어장을 만들어 주자.입니다.
* * *
### 풀이과정
* 우선 단어의 갯수와 단어의 길이 기준인 m을 입력 받은 다음에 n번 만큼 반복문을 돌려 단어를 입력받는다.<br>
단어가 딕셔너리에 없을 경우 추가 해주고 카운트 기준값인 1을 딕셔너리의 값으로 추가해준다.<br>
만약에 딕셔너리에 있으면 값에 1을 더하여 업데이트 해준다.<br>
딕셔너리에서 어떤 조건에 못미칠경우 바로 삭제를 해주면 안되기 때문에 애초에 딕셔너리 값을 전체적으로 수정해줘야된다.<br>
따라서 m보다 길이가 같거나 클 경우에만 딕셔너리에 포함되게만 해주면 된다.<br>
<code> eng={key:value for key,value in eng.items() if len(key)>=m}</code>
우선 순위에서 어떻게 해야할지 몰라서 구글링을 하였다<br>
파이썬에서는 익명함수 lambda함수가 있는데, lambda함수에선 다중정렬을 할수있다.<br>
lambda x: (우선순위1, 우선순위 2, 우선순위 3...) lambda x의 익명함수에 튜플형식으로 우선순위를 지정해주면<br>
그 순위대로 정렬을 해줄수 있다.
<code>eng=sorted(eng.items(),key=lambda x: (-x[1],-len(x[0]),x[0]))</code>

### 코드
<pre>
<code>
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

  
</code>
</pre>
### 링크
<https://www.acmicpc.net/problem/20920>
