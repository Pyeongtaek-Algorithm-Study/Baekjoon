## [백준 10972번](https://www.acmicpc.net/problem/10972) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 다음에 오는 순열을 구하는 프로그램을 작성하시오.

사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.

N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.

1, 2, 3
1, 3, 2
2, 1, 3
2, 3, 1
3, 1, 2
3, 2, 1

#### 입력
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.

#### 출력
첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 출력한다. 만약, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다.

#### 예제
> **입력**
4
1 2 3 4

> **출력**
1 2 4 3

## 해설
1의 자릿수(맨 오른쪽 숫자)부터 시작하여 오름차순이 되는 순열을 찾고, 오름차순이 끝난 수의 다음 숫자의 인덱스를 digit1에 저장하고, 아까 찾은 순열 안에서 digit1번째 수보다 크면서 최솟값인 수의 인덱스를 digit2에 저장해준 후 digit1번째 수와 digit2번째 수를 swap시켜줍니다. 이후 아까 찾은 오름차순 순열을 내림차순으로 변경해줍니다.

> 1. 1의 자릿수부터 오름차순이 되는 순열을 찾는다.
2. 오름차순이 끝난 수의 다음 숫자의 인덱스를 digit1에 저장.
3. 순열에서 digit1번째 수보다 크면서 최솟값인 수의 인덱스를 digit2에 저장.
4. digit1번째 수와 digit2번째 수를 swap 후 오름차순 순열을 내림차순으로 변경.

## 답안
```
import java.io.*;
import java.util.stream.Stream;

public class Main {
	static int n;
	static int[] arr;
	
	private static boolean nextNums() {
		int digit1 = n - 1;
		while(digit1 > 0 && arr[digit1] < arr[digit1 - 1]) digit1--;
		if (digit1 <= 0) return false;
		
		int digit2 = n - 1;
		while(arr[digit2] < arr[digit1 - 1]) digit2--;
		
		swap(digit1 - 1, digit2);
		digit2 = n - 1;
		while(digit1 < digit2) {
			swap(digit1, digit2);
			digit1++; digit2--;
		}
		
		return true;
	}
	
	private static void swap(int num1, int num2) {
		int temp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = temp;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		String[] tempArr = br.readLine().split(" ");
		arr = Stream.of(tempArr).mapToInt(Integer::parseInt).toArray();
		
		if(nextNums()) {
			for(int i = 0; i < n; i++) {
				System.out.print(arr[i] + " ");
			}
		}
		else {
			System.out.println(-1);
		}
	}

}
```
