import java.io.*;
import java.util.*;

public class Main
{
    static int n;
    static int[] spendTime;
    static int[] indegree;
    static ArrayList<ArrayList<Integer>> preBuild;
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
        n = Integer.parseInt(br.readLine());
        preBuild = new ArrayList<>();
        
        for (int i = 0; i <= n; i++) {
            preBuild.add(new ArrayList<>());
        }
        
        spendTime = new int[n + 1];
        indegree = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            
            spendTime[i] = Integer.parseInt(st.nextToken());
            while (true) {
                int el = Integer.parseInt(st.nextToken());
                if (el == -1) break;
                
                preBuild.get(el).add(i);
                
                indegree[i]++;
            }
        }
        
		solve();
		
		br.close();
	}
	
	public static void solve() {
	    Queue<Integer> q = new LinkedList<>();
	    
	    for (int i = 1; i <= n; i++) {
	        if (indegree[i] == 0) {
	            q.offer(i);
	        }
	    }
	    
	    int[] res = new int[n + 1];
	    
	    while (!q.isEmpty()) {
	        int now = q.poll();
	        
	        for (int nxt : preBuild.get(now)) {
	            indegree[nxt]--;
	            
	            res[nxt] = Math.max(res[nxt], res[now] + spendTime[now]);
	            
	            if (indegree[nxt] == 0) {
	                q.offer(nxt);
	            }
	        }
	    }
	    
	    StringBuilder sb = new StringBuilder();
	    for (int i = 1; i <= n; i++) {
	        sb.append((res[i] + spendTime[i]) + "\n");
	    }
	    
	    System.out.println(sb.toString());
	}
}
