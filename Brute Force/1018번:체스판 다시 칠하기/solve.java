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
