import java.io.*;
import java.util.*;

public class Main
{
    static int MAX = Integer.MIN_VALUE;
    static int MIN = Integer.MAX_VALUE;
    static int[] operator = new int[4];
    static int[] nums;
    static int n;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		nums = new int[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
		    nums[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < 4; i++) {
		    operator[i] = Integer.parseInt(st.nextToken());
		}
		
		dfs(nums[0], 1);
		
		System.out.println(MAX);
		System.out.println(MIN);
	}
	
	private static void dfs(int num, int idx) {
	    if (idx == n) {
	        MAX = Math.max(MAX, num);
	        MIN = Math.min(MIN, num);
	        return;
	    }
	    
	    for (int i = 0; i < 4; i++) {
    	    if (operator[i] > 0) {
    	        // 해당 연산자 횟수 감소
    	        operator[i]--;
    	        
    	        switch (i) {
    	            case 0:
    	                dfs(num + nums[idx], idx + 1);
    	                break;
    	            case 1:
    	                dfs(num - nums[idx], idx + 1);
    	                break;
	                case 2:
    	                dfs(num * nums[idx], idx + 1);
    	                break;
    	            case 3:
    	                dfs(num / nums[idx], idx + 1);
    	                break;
    	        }
    	        
    	        operator[i]++;
    	    }
	        
	    }
	    
	}
}