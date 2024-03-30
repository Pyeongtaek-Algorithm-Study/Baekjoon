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
