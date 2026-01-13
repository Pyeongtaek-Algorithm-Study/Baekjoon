import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;  // c++의 vector<>와 비슷
import java.util.Queue;
import java.util.LinkedList; // Queue

public class Main
{
    static int n;
    static ArrayList<ArrayList<Integer>> al = new ArrayList<>();
    static int[] indegree;
    static int[] time;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		indegree = new int[n + 1];
		time = new int[n + 1];
		
		al.add(new ArrayList<Integer>());
		for (int i = 1; i <= n; i++) {
		    al.add(new ArrayList<Integer>());
		    st = new StringTokenizer(br.readLine());
		    
		    time[i] = Integer.parseInt(st.nextToken());
		    int needCnt = Integer.parseInt(st.nextToken());
		    
		    for (int c = 1; c <= needCnt; c++) {
		        int tmp = Integer.parseInt(st.nextToken());
		        al.get(tmp).add(i);
		        
		        indegree[i]++;
		    }
		}
		
		System.out.println(solve());
	}
	
	private static int solve() {
	    int ans = 0;
	    int[] res = new int[n + 1];
	    Queue<Integer> q = new LinkedList<>();
	    
	    for (int i = 1; i <= n; i++) {
	        res[i] = time[i];
	        
	        if (indegree[i] == 0) {
	            q.offer(i);
	        }
	    }
	    
	    while (!q.isEmpty()) {
	        int cur = q.poll();
	        
	        for (int nxt : al.get(cur)) {
	            indegree[nxt]--;
	            
	            res[nxt] = Math.max(res[nxt], res[cur] + time[nxt]);

	            if (indegree[nxt] == 0) {
	                q.offer(nxt);
	            }
	        }
	    }
	    
	    
	    for (int i = 1; i <= n; i++) {
	        ans = Math.max(ans, res[i]);
	    }
	    
	    return ans;
	}
}