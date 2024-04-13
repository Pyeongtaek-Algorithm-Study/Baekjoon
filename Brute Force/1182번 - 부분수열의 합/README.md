## [백준 1182번](https://www.acmicpc.net/problem/1182) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

#### 입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

#### 출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

#### 예제1
> **입력**
5 0
-7 -3 -2 5 8

> **출력**
1

## 해설
브루트포스 알고리즘 문제이기 때문에 전체탐색으로 코드를 작성했습니다.

**접근방식**

1. 주어진 정수 중 2개 이상 합쳐서 나올 수 있는 모든 경우의 수를 확인합니다.

3. 재귀를 통하여 모든 경우의 수를 구하고 S와 같은 경우를 찾습니다.

## 답안
```
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int n, s;
	static int result = 0;
	static int[] arr;
	
	private static void count(int length, int sum) {
		if(sum == s) result++;
		for(int i = length; i < n; i++) {
			count(i + 1, sum + arr[i]);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		
		arr = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i < n; i++) {
			count(i + 1, arr[i]);
		}
		System.out.println(result);
	}

}
```
