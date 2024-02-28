## [백준 2407번](https://www.acmicpc.net/problem/2407) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
nCm을 출력한다.

#### 입력
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

#### 출력
nCm을 출력한다.

#### 예제
> **입력**
100 6

> **출력**
1192052400

## 해설
처음 봤을 때 long으로 풀어봤는데 long의 범위를 한참 넘어버려서 실패하였습니다.

그래서 전에 팩토리얼 관련 문제를 풀 때도 다이나믹 프로그래밍 개념을 사용하였고, 파스칼의 삼각형을 이용하여 문제를 풀었기 때문에 이번에도 그렇게 풀어보기로 정했습니다.
![파스칼의 삼각형](https://velog.velcdn.com/images/dlwodbs1223/post/e14e2090-00cc-43bd-a0f2-457137feb2fc/image.png)

파스칼의 삼각형을 구현해 줄 dp라는 2차원 배열을 만들었습니다. 삼각형의 가장자리 부분을 1로 채워준 후 파스칼의 삼각형이 구해지는 공식(밑에 참고)을 생각하여 삼각형을 모두 채우고, 마지막으로 \[n]\[m]번째를 출력해줍니다.

> **공식**
dp\[i]\[j] = dp\[i-1]\[j] + dp\[i-1]\[j-1]

## 답안
```
import java.io.*;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main {
	static int n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		BigInteger[][] dp = new BigInteger[101][101];
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if(j == 0 || j == i) dp[i][j] = BigInteger.ONE;
				else dp[i][j] = dp[i - 1][j].add(dp[i - 1][j - 1]);
			}
		}
		System.out.println(dp[n][m]);
	}

}
```
<br><br><br>
