import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int testCase = Integer.parseInt(br.readLine());
		
		for (int tc = 0; tc < testCase; tc++) {
		    int n = Integer.parseInt(br.readLine());
		    int[] arr = new int[n];
		    
		    
		    st = new StringTokenizer(br.readLine());
		    for (int i = 0; i < n; i++) {
		        arr[i] = Integer.parseInt(st.nextToken());        
		    }
		    
		    solve(arr, n);
		}
	}
	
	public static void solve(int[] arr, int len) {
		
		long sum = 0;
		int max = -1;
		
	    for (int i = len - 1; i >= 0; i--) {
	    	if (arr[i] <= max) {
	    		sum += (max - arr[i]);
	    	}
	    	else {
	    		max = arr[i];
	    	}
	    }
	    
	    System.out.println(sum);
	}
}
