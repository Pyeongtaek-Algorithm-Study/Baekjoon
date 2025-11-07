import java.io.*;
import java.util.*;

public class Main
{
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    static int ans = 0;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int root = -1;
		
		for (int i = 0; i < n; i++) {
		    tree.add(new ArrayList<>());
		}
		
		StringTokenizer st =new StringTokenizer(br.readLine(), " ");
		    
	    for (int j = 0; j < n; j++) {
	        int node = Integer.parseInt(st.nextToken());
	        
	        if (node == -1) {
	            root = j;
	            continue;
	        }
	        tree.get(node).add(j);
	    }
		
		int rm = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
		    if (tree.get(i).contains(rm)) {
		        tree.get(i).remove(Integer.valueOf(rm));
		    }
		}
		    
	    if (rm == root) {
	        ans = 0;
	    }
	    else {
	        dfs(root);
	    }
	    
	    System.out.println(ans);
	}
	
	static private void dfs(int node) {
	    
	    if (tree.get(node).isEmpty()) {
	        ans++;
	        return;
	    }
	    
	    for (int nextNode : tree.get(node)) {
	        dfs(nextNode);
	    }
	}
}
