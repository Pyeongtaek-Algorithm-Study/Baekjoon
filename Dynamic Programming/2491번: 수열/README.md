백준 2491번: 수열
=============
<https://www.acmicpc.net/problem/2491>

0에서부터 9까지의 숫자로 이루어진 N개의 숫자가 나열된 수열이 있다.
그 수열 안에서 연속해서 커지거나(같은 것 포함), 혹은 연속해서 작아지는(같은 것 포함) 수열 중 가장 길이가 긴 것을 찾아내어 그 길이를 출력

<처음 풀이>
-------------

증가할땐 +, 감소할땐 -, 같을땐 =으로 다음 요소와 비교하며 스택에 넣어줬다.
스택 길이만큼 반복문을 하여 직접 카운트를 써줬는데 =연산때문에 조건이 많이 추가되고 코드도 복잡해졌다.
dp를 어떻게 사용해야하는지 구글링을 했다.

* * *

<풀이>
-------------

dp테이블을 두개 만들어주는데, 증가하는 dp, 감소하는 dp이다.

증가하거나 같을때 갯수를 세고, 그 수를 증가하는 dp에 갯수를 넣어준다.

중간에 감소하거나 같게 되면, 감소하는 dp에 갯수를 넣어준다.

또 증가가 되면, 증가하는 dp는 다음 인덱스로 넘어가서 1부터 다시 갯수를 세어 그 인덱스에 값을 넣어준다.

그러면 증가할때 마다, 감소할때 마다 길이를 추가해줄수 있다.

dp[1]*N인 이유는 증가하는 수열 또는 감소하는 수열의 길이는 N보다 크지 않기 때문에 N으로 해주고, 수열의 최소 길이는 1이기 때문에 1로 초기화 해준다.

감소하는 dp, 증가하는 dp에는 수열의 길이가 각각 저장이 되어 있기 때문에 거기서 max값을 구하면 된다.

