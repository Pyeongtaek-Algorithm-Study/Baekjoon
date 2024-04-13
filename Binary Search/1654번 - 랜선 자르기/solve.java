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
