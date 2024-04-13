import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int[] arr;
  
	private static int lowerBound(int key) {
		int left = 0;
		int right = arr.length;
		
		while(left < right) {
			int mid = (left + right) / 2;
			if(key <= arr[mid]) right = mid;
			else left = mid + 1;
		}
		return left;
	}
	
	private static int upperBound(int key) {
		int left = 0;
		int right = arr.length;
		
		while(left < right) {
			int mid = (left + right) / 2;
			if(key < arr[mid]) right = mid;
			else left = mid + 1;
		}
		return left;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		arr = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < m; i++) {
			int key = Integer.parseInt(st.nextToken());
			int count = 0;
			sb.append(upperBound(key) - lowerBound(key)).append(" ");
		}
		
		System.out.println(sb);
	}

}
