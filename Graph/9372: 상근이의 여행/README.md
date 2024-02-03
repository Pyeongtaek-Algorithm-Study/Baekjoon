## [백준 9372번](https://www.acmicpc.net/problem/9372) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
상근이는 겨울방학을 맞아 N개국을 여행하면서 자아를 찾기로 마음먹었다. 

하지만 상근이는 새로운 비행기를 무서워하기 때문에, 최대한 적은 종류의 비행기를 타고 국가들을 이동하려고 한다.

이번 방학 동안의 비행 스케줄이 주어졌을 때, 상근이가 가장 적은 종류의 비행기를 타고 모든 국가들을 여행할 수 있도록 도와주자.

상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다.

#### 입력
첫 번째 줄에는 테스트 케이스의 수 T(T ≤ 100)가 주어지고,

각 테스트 케이스마다 다음과 같은 정보가 주어진다.

첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
이후 M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b) 
주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.

#### 출력
테스트 케이스마다 한 줄을 출력한다.

상근이가 모든 국가를 여행하기 위해 타야 하는 비행기 종류의 최소 개수를 출력한다.

#### 예제
> **입력**
2
3 3
1 2
2 3
1 3
5 4
2 1
2 3
4 3
4 5

> **출력**
2
4

## 해설
사실 이 문제는 그래프의 성질을 알고 있으면 간단하게 해결되는 문제입니다. t라는 그래프에 n개의 정점이 있을 경우 그래프 t의 최소 간선의 개수는 n-1개입니다. 여기서 국가는 정점이 되고 간선은 비행기가 됩니다. 따라서 답은 n-1개로 간단하게 해결되는 문제입니다.

하지만, 저는 BFS를 이용하여 문제를 풀어보았습니다. 비행기(간선)를 표시해줄 인접행렬 arr와 방문을 표시하기 위한 visit, 국가(정점) 이동을 카운트 해줄 count를 전역변수(static)로 선언하여서 BFS() 메소드와 main() 메소드에서 사용할 수 있도록 하였고, BFS를 통해 그래프 t에서의 정점 1부터 시작하였을 때 최소 간선의 개수를 구할 수 있습니다.

> 1. BFS를 이용하여 문제 해결
2. 인접행렬 arr, 방문을 표시하는 visit, 정점 이동 count를 전역변수로 선언
>3. BFS를 통해 그래프 t에서의 정점 1부터 시작하였을 때 최소 간선의 개수를 구함.

## 답안
```
import java.io.*;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class Num9372 {
	static boolean[] visit;
	static int[][] arr;
	static int n, m, count;
	
	private static void BFS() {
		Queue<Integer> queue = new LinkedList<Integer>();
		visit[1] = true;
		queue.add(1);
		while(!queue.isEmpty()) {
			count++;
			int vertex = queue.poll();
			for (int i = 1; i <= n; i++) {
				if(arr[vertex][i] != 0 && !visit[i]) {
					visit[i] = true;
					queue.add(i);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			count = 0;
			arr = new int[n+1][n+1];
			visit = new boolean[n+1];
			
			for (int j = 0; j < m; j++) {
				st = new StringTokenizer(br.readLine(), " ");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				arr[a][b] = 1;
				arr[b][a] = 1;
			}
			BFS();
			System.out.println(count - 1);
		}
	}
	
}
```
