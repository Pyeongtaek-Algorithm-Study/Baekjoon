# 1256번: 사전
### 문제해설
* 이 문제는 'a'와 'z'로 이루어진 문자열에서 알파벳 순서대로 사전을 만들 때, K번째의 문자열을 찾는 문제입니다.<br>
각 문자열은 N개의 'a'와 M개의 'z'로 구성되어 있으며, 사전은 알파벳 순서대로 정렬되어 있습니다. 동호는 K번째의 문자열을 찾아야 합니다.
* * *
### 풀이과정
* 조합론이라 처음에는 순열 라이브러리를 이용해서 모든 순열을 구한후, 중복을 제거하고, 올림차순을 해주었다.<br>
그리고 k와 순열의 길이를 구하여 비교해준후, k가 더 크면 -1, 아니면 k번째 순열을 구하게 하였다.<br>
시간 초과가 너무 많이 떠서 구글링으르 해주었다.
* * *

* 내가 찾아본 방법으로는 모든 순열을 구하지 않고, 경우의 수만 구해내어 k번째 순열을 구하는 것이다.<br>
우선 전체 조합의 수를 구한다. 전체 문자의 수는 n개인 a와 m개인 z이니 n+m개이고, 거기서 n개를 고르는 경우의 수는 <br>
n+m개에서 m개를 고르는 경우의 수와 같으니, comb함수를 이용해 전체 조합의 수를 comb(n+m,n)으로 구해낸다.<br>
전체 조합의 수가 k보다 작으면 -1을 출력해주고 아니면 k번째의 수열을 구해줘야된다. <br>
우선 a가 먼저 와야되므로 a를 선택하고 남은 경우의 수를 구해준다. <br>
comb(n+m-1,n-1)로 구해주면 a를 선택하고 남은 경우의 수가 구해지는데, 이게 k보다 작으면<br>
a를 선택하고 남은 경우들이 모두 k번째보다 앞에 있다는 뜻이다. <br>
이제 a는 선택했으니 n에 1을 뺴주고, result 배열에 a를 추가해주면 된다.<br>
만약에 아니면 z부터 순열을 구해주는게 더 유리하다. <br>
z를 선택했으니 m에 1을 빼주고, result배열에 z를 추가해준다. 또한 제일 큰수인 z가 선택 되었으니<br>
현재 위치에서의 조합의 개수를 해줘야한다.<br>
이런식으로 a와 z의 수 n,m이 0이 될때까지 반복문을 돌려준다. <br>
만약 더 남아있는 n이나 m이 있으면 extend함수로 문자열을 채워준다.<br>
### 코드
<pre>
<code>
import math

def find_kth_string(N, M, K):
    total_strings = math.comb(N + M, N)  # 전체 문자열의 개수는 조합(N+M, N)과 같다.

    if K > total_strings:
        return -1  # K가 문자열의 개수보다 크면 -1을 반환

    result = []
    while N > 0 and M > 0:
        combinations = math.comb(N + M - 1, N - 1)  # 현재 위치에서의 조합을 계산
        if K <= combinations:
            result.append('a')
            N -= 1
        else:
            result.append('z')
            M -= 1
            K -= combinations

    result.extend(['a'] * N)
    result.extend(['z'] * M)

    return ''.join(result)

# 입력 예제
N, M, K = map(int, input().split())

# 결과 출력
answer = find_kth_string(N, M, K)
print(answer)



  
</code>
</pre>

### 링크
<https://www.acmicpc.net/problem/1256>

