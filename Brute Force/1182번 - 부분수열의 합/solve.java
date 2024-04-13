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
