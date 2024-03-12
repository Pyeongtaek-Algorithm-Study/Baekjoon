## [백준 15649번](https://www.acmicpc.net/problem/15649) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

#### 입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

#### 출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

#### 예제
> **입력**
4 2

> **출력**
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3

## 해설
방문을 기록해 줄 n만큼 크기를 가진 배열과 수열을 기록해 줄 m만큼 크기를 가진 배열을 선언하고, DFS 메소드를 재귀호출하여 수열을 출력하는 방식으로 코드를 작성하였습니다. depth를 M과 같아지면 더이상 재귀를 호출하지 않고 탐색과정 중 값을 담았던 arr 배열을 출력하도록 작성하여 재귀를 통제하였습니다.

> 1.방문을 기록해 줄 배열, 수열을 기록해 줄 배열 선언.
2. DFS 메소드를 재귀호출하여 수열을 출력하는 방식으로 코드를 작성.
3. depth를 이용하여 재귀 통제.

## 답안
```
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static boolean[] visit;
	static int[] arr;
	
	private static void DFS(int n, int m, int depth) {
		if (depth == m) {
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
			return;
		}
	 
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				arr[depth] = i + 1;
				DFS(n, m, depth + 1);
				visit[i] = false;
			}
		}
		return;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		visit = new boolean[n];
		arr = new int[m];
		
		DFS(n, m, 0);
	}

}
```
