import java.io.*;
import java.util.*;

public class Main
{
    static int n;
    static int[] arr;
    static boolean[] vis;
    static int[] tmpArr;
    static int maxValue = Integer.MIN_VALUE;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		arr = new int[n + 1];
		vis = new boolean[n + 1];
		tmpArr = new int[n + 1];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
		    arr[i] = Integer.parseInt(st.nextToken());
		}
		
		back(0);
		System.out.println(maxValue);
	}
	
	public static void back(int idx) {
	    if (idx == n) {
	        int sumValue = 0;
	        
	        for (int i = 0; i < n - 1; i++) {
	            sumValue += Math.abs(tmpArr[i] - tmpArr[i + 1]);
	        }
	        
	        maxValue = Math.max(maxValue, sumValue);
	    }
	    
	    for (int i = 0; i < n; i++) {
	        if (!vis[i]) {
	            vis[i] = true;
    	        tmpArr[idx] = arr[i];
    	        back(idx + 1);
    	        vis[i] = false;    
	        }
	    }
	}
}