# 1256번: 로또
### 문제해설
* 1부터 49까지의 숫자 중 k개를 선택하여 집합 S를 만듭니다.
집합 S에서 가능한 모든 6개의 숫자 조합을 찾습니다.
조합을 출력하거나 저장하여 수를 고르는 모든 방법을 확인합니다.
* * *
### 풀이과정
* combinations 함수를 사용하기 위해 itertools 모듈을 import해주었다.<br>
def func(arr) 함수를 정의하였다. 이차원 리스트 arr를 입력받아 함수를 실행시켜준다.<br>
입력으로 받은 리스트 `arr`에 대해 반복문을 실행한다.
c_lst=list(combinations(i[1:],6)) 코드를 써서 현재 리스트의 첫 번째 요소를 제외한 나머지 요소들로부터 6개의 조합을 만들어 `c_lst`에 저장하였다. <br>
for j in c_lst로 각 조합에 대해 반복문을 실행하였다.
print(' '.join(map(str, j))로 각 조합을 문자열로 변환하여 출력하였다.<br>
원래 나는 ''.join(배열)을 해야지 배열을 문자열로 바꾸어주는줄 알았는데, 배열에 숫자가 있으면, map함수로 요소들을 일일히<br>
문자로 바꿔준다음에 합쳐줘야 하는 것이였다. map(str, j)는 각 요소를 문자열로 변환하고, join() 함수는 문자열을 공백으로 연결하는 것이다.<br>
print()로 각 리스트 조합을 출력한 후 빈 줄을 출력하여 구분한다.
마지막으로 사용자로부터 숫자를 입력받아 리스트 `arr`에 저장하고, 입력된 숫자가 0이면 프로그램이 종료된다.

### 코드
<pre>
<code>
from itertools import combinations


def func(arr):
    for i in arr:
        c_lst=list(combinations(i[1:],6))
        # print(c_lst)
        for j in c_lst:
            print(' '.join(map(str, j)))
        print()

arr=[]
while True:
    lst=list(map(int,input().split()))
    if lst[0]==0:
        break
    arr.append(lst)

func(arr)

  
</code>
</pre>

### 링크
<https://www.acmicpc.net/problem/6603>
