## [백준 1654번](https://www.acmicpc.net/problem/1654) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

#### 입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.

#### 출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

#### 예제1
> **입력**
4 11
802
743
457
539

> **출력**
200

## 해설

**제가 직접 푼 코드입니다. 하지만 시간초과로 실패...**
```
import java.io.*;
import java.util.StringTokenizer;


public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int[] arr = new int[k];
		double sum = 0;
		
		for(int i = 0; i < k; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			sum += arr[i];
		}
		
		int avg = (int)Math.round(sum / k);
		int cnt = 0;
		
		for (int i = avg; i > 0; i--) {
			cnt = 0;
			for (int j = 0; j < k; j++) {
				cnt += arr[j] / i;
			}
			if (cnt == n) {
				System.out.println(i);
				break;
			}
		}
	}
	
}
```

브루트포스 알고리즘처럼 주어진 랜선의 모든 합을 n개만큼 나눈 값을 avg라 하고, 그 값부터 1씩 줄여서 주어진 랜선에 나눈 값을 cnt에 저장해주고 n이랑 비교했을 때 동일하면 그 값을 출력하도록 설정하였지만 시간 초과로 실패.... 이후 다른 분들의 접근방식을 보면서 풀이해봤습니다.

**접근방식**
알고리즘 분류대로 이진(이분) 탐색을 응용하여 풀어야하는 문제
주의사항으로는 랜선의 길이는 0이 될 수 없으므로 1이상이여야 하는 점, 주어진 랜선의 합이 int의 범위를 넘어가는 경우를 고려하여 long타입을 사용해야 하는 점이 있습니다.


## 답안
**이진(이분) 탐색 정석 풀이**
```
import java.io.*;
import java.util.StringTokenizer;


public class Main {
	static int k, n;
	static int[] arr;
	
	private static int BinarySearch(long min, long max) {
		long mid = 0;
		
		while(min <= max) {
			int cnt = 0;
			mid = (min + max) / 2;
			
			for (int i = 0; i < k; i++) {
				cnt += arr[i] / mid;
			}
			
			if(cnt < n) max = mid - 1;
			else min = mid + 1;
		}
		return (int)max;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		k = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr = new int[k];
		long max = 0;
		
		for(int i = 0; i < k; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			if(max < arr[i]) max = arr[i];
		}
		
		System.out.println(BinarySearch(1, max));
	}
	
}
```

**다른 분이 이진(이분) 탐색 중 Upper Bound로 푸신 접근 방법을 보고 풀어봤습니다.**
```
import java.io.*;
import java.util.StringTokenizer;


public class Main {
	static int k, n;
	static int[] arr;
	
	private static int UpperBinarySearch(long min, long max) {
		long mid = 0;
		
		while(min < max) {
			int cnt = 0;
			mid = (min + max) / 2;
			
			for (int i = 0; i < k; i++) {
				cnt += arr[i] / mid;
			}
			
			if(cnt < n) max = mid;
			else min = mid + 1;
		}
		return (int)min - 1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		k = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr = new int[k];
		long max = 0;
		
		for(int i = 0; i < k; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			if(max < arr[i]) max = arr[i];
		}
		
		System.out.println(UpperBinarySearch(0, max + 1));
	}
	
}
```
