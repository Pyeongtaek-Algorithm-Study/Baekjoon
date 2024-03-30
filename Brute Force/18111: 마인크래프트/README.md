## 마인크래프트 자바 풀이 : [18111번 바로가기](https://www.acmicpc.net/problem/18111)

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다. 마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.

목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업을 해야 한다.

lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다. 우리는 다음과 같은 두 종류의 작업을 할 수 있다.

좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다. ‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다. 땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

#### 입력
첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)

둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다. 땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.

#### 출력
첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.

#### 예제1
> **입력**
3 4 1
64 64 64 64
64 64 64 64
64 64 64 63

> **출력**
1 64

![image](https://github.com/Pyeongtaek-Algorithm-Study/Baekjoon/assets/154980427/cca645e3-b011-4517-97c9-6b37c5c9e1fa)


## 해설

**접근방식**
브루트포스 알고리즘을 사용하면 시간복잡도가 256\*500\*500이기 때문에 사용 가능하다고 판단하였습니다.

1. 땅의 높이를 입력 받을 때 최소 높이(min)와 최대 높이(max)를 구합니다.

2. 땅의 높이를 min부터 max까지로 범위를 좁히고 모든 경우 중 최소 시간 값을 구합니다.

3. 최소 시간이 같은 경우 중 최대 높이를 구합니다.

주의 사항으로는 보유 중인 블록보다 더 사용한 경우는 제외하여야 합니다.

## 답안
```
import java.io.*;
import java.util.StringTokenizer;


public class Main {
	static int n, m, b, height;
	static int[][] arr;
	
	private static int count(int min, int max) {
		int result = Integer.MAX_VALUE;
		height = min;
		
		while(min <= max) {
			int num = b, time = 0;
			for (int i = 0; i < n; i++) {
				if (result <= time) break;
				for (int j = 0; j < m; j++) {
					int temp = arr[i][j] - min;
					if (temp > 0) time += 2 * temp;
					else if (temp < 0) time -= temp;
					num += temp;
				}
			}
			
			if (result >= time && num >= 0) {
				result = time;
				height = min;
			}
			min++;
		}
		
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		
		arr = new int[n][m];
		int max = 0, min = Integer.MAX_VALUE;
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(max < arr[i][j]) max = arr[i][j];
				if(min > arr[i][j]) min = arr[i][j];
			}
		}
		System.out.printf("%d %d", count(min, max), height);
	}
	
}
```
