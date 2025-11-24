import java.io.*;
import java.util.*;

public class Main
{
    static int[] parent;
    static int[] frCost;
    static int[] minCost;
    static int n, m, k;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
        
        frCost = new int[n + 1];
        parent = new int[n + 1];
        minCost = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            frCost[i] = Integer.parseInt(st.nextToken());
            minCost[i] = frCost[i];
        }
        
        List<int[]> rel = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            rel.add(new int[] {v, w});
        }
		
		solve(rel);
		
		br.close();
	}
	
	public static void solve(List<int[]> list) {
	    for (int[] tmp : list) {
	        // Union
	        int a = Find(tmp[0]);
	        int b = Find(tmp[1]);
	        if (a != b) {
	            if (minCost[a] < minCost[b]) {
	                parent[b] = a;
	                minCost[b] = minCost[a];
	            }
	            else {
	                parent[a] = b;
	                minCost[a] = minCost[b];
	            }
	        }
	    }
	    
	    int sum = 0;
	    for (int i = 1; i <= n; i++) {
	        // 해당 그룹의 부모의 비용만 합산
	        if (parent[i] == i) {
	            sum += minCost[i];
	        }
	    }
	    
	    // 전체 친구를 사귀기 위한 비용과 k값 비교 후 출력
	    System.out.println(sum <= k ? sum : "Oh no");
	}
	
	public static int Find(int x) {
	    if (parent[x] == x) return x;
	    return parent[x] = Find(parent[x]);
	}
}