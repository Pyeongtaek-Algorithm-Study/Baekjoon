import java.io.*;
import java.util.*;

public class Main
{
    private static int n, m;
    private static int[] haveNum;
    private static int[] findNum;
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    n = Integer.parseInt(br.readLine());
	    haveNum = new int[n];
	    st = new StringTokenizer(br.readLine());
	    for (int i = 0; i < n; i++) {
	        haveNum[i] = Integer.parseInt(st.nextToken());
	    }
	    m = Integer.parseInt(br.readLine());
	    findNum = new int[m];
	    st = new StringTokenizer(br.readLine());
	    for (int i = 0; i < m; i++) {
	        findNum[i] = Integer.parseInt(st.nextToken());
	    }
	    
	    solve();

        br.close();	
	}
	
	static void solve() {
	    HashSet<Integer> ans = new HashSet<>();
	    
	    for (int tmp : haveNum) {
	        ans.add(tmp);
	    }
	    
	    StringBuilder sb = new StringBuilder();
	    
	    for (int obj : findNum) {
	        sb.append(ans.contains(obj) ? 1 : 0)
	        .append(" ");
	    }
	    
	    System.out.println(sb.toString());
	}
}