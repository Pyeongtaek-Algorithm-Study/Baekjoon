import java.io.*;
import java.util.*;

public class Main
{
    static int n, m;
    static List<Integer>[] path;
    static boolean[] visited;
    static int[] hackCnt;
    
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        visited = new boolean[n + 1];
        hackCnt = new int[n + 1];
        path = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            path[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            path[a].add(b);
        }
        
        solve();
        br.close();
	}
	
	public static void solve() {
	    for (int i = 1; i <= n; i++) {
	        visited = new boolean[n + 1];
	        bfs(i);
	    }
	    
	    int maxVal = Integer.MIN_VALUE;
	    for (int i = 1; i <= n; i++) {
	        maxVal = Math.max(maxVal, hackCnt[i]);
	    }
	    
	    StringBuilder sb = new StringBuilder();
	    for (int i = 1; i <= n; i++) {
	        if (hackCnt[i] == maxVal) {
	            sb.append(i + " ");
	        }
	    }
	    
	    System.out.println(sb.toString());
	}
	
	public static void bfs(int st) {
	    Queue<Integer> q = new LinkedList<>();
        visited[st] = true;
	    q.add(st);
	    
	    int cnt = 0;
	    
	    while (!q.isEmpty()) {
	        int cur = q.poll();
	        
	        for (int nxt : path[cur]) {
	            if (visited[nxt]) continue;
	            
	            visited[nxt] = true;
	            hackCnt[nxt]++;
	            q.add(nxt);
	        }
	    }
	}
}
