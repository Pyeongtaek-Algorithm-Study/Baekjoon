## [백준 1018번](https://www.acmicpc.net/problem/1018) 자바 풀이

**문제는 백준 사이트와 똑같으니, 해설부터 보셔도 됩니다.**

#### 문제
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

#### 입력
첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

#### 출력
첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

#### 예제1
> **입력**
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

> **출력**
1

## 해설
브루트포스 알고리즘 문제이기 때문에 전체탐색으로 코드를 작성했습니다.

**접근방식**

1. 주어진 n \* m에서 8 \* 8이 되는 체스판들의 시작 위치(좌표)는 0, 0부터 m - 8, n - 8까지입니다.
![](https://velog.velcdn.com/images/dlwodbs1223/post/46bf2886-8f05-4a32-bb79-141b1204f80f/image.png)
위 사진에서 검은색 사각형은 m \* n이고, 초록색은 첫번째 체스판, 빨간색은 마지막 체스판입니다. 그림처럼 시작 위치는 각각 (0, 0), (m-8, n-8)입니다.

2. 흑으로 시작할 경우와 백으로 시작할 경우 각각 바꿔야할 정사각형의 개수가 다릅니다.

> 1. 브루트포스 문제이기 때문에 모든 경우의 수 전체 탐색
2. 체스판의 시작 위치는 (0, 0)부터 (m-8, n-8)까지
3. 모든 경우의 수 = (m-8) \* (n-8) \* 2 \* 8 \* 8

## 답안
```
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	
	private static int count(String[] arr) {
		int result = Integer.MAX_VALUE;
		for(int i = 0; i < n - 7; i++) {	// 8x8 시작 좌표(y)
			for(int j = 0; j < m - 7; j++) {	// 8x8 시작 좌표(x)
				for (int k = 0; k < 2; k++) {	// 백 시작일 때와 흑 시작일 때 변경해야될 개수가 다르기 때문에 두번 반복
					boolean tf = k == 0 ? true : false; // 처음에는 true 백 시작, false 흑 시작
					int count = 0;	// 변경해야되는 정사각형 개수를 카운트
					for (int y = i; y < i + 8; y++) {		// 시작 좌표부터 +8까지 (y)
						for (int x = j; x < j + 8; x++) {	// 시작 좌표부터 +8까지 (x)
							if((arr[y].charAt(x) == 'W') != tf) count++;	// 현재 좌표에 있어야할 값이 맞는지 틀린지 확인
							tf = !tf;
						}
						tf = !tf;		// 짝수(8x8)라 줄 바뀔 때 한번 더 변경
					}
					if (count < result) result = count;
				}
			}
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		String[] arr = new String[n];
		
		for(int i = 0; i < n; i++) {
			arr[i] = br.readLine();
		}
		
		System.out.println(count(arr));
		
	}

}
```
