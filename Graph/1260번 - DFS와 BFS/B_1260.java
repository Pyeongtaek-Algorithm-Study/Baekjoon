import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B_1260 {

	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		
		
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		
		int N = Integer.parseInt(stringTokenizer.nextToken());
		int M = Integer.parseInt(stringTokenizer.nextToken());
		int V = Integer.parseInt(stringTokenizer.nextToken());
		
		graph = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++)
		{
			graph[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < M; i++)
		{
			stringTokenizer = new StringTokenizer(bufferedReader.readLine());
			int u = Integer.parseInt(stringTokenizer.nextToken());
			int v = Integer.parseInt(stringTokenizer.nextToken());
			graph[u].add(v);
			graph[v].add(u);
		}
		
		for (int i = 1; i <=N; i++)
		{
			Collections.sort(graph[i]);
		}
		
		visited = new boolean[N + 1];
		dfs(V);
		System.out.println();
		
		visited = new boolean[N + 1];
		bfs(V);
		
	}
	
	public static void dfs(int node)
	{
		visited[node] = true;
		System.out.print(node + " ");
		
		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				dfs(neighbor);
			}
		}
			
	}
	
	public static void bfs(int start)
	{
		Queue<Integer> queue = new LinkedList<>();
		visited[start] = true;
		queue.add(start);
		
		while (!queue.isEmpty()) {
			int node = queue.poll();
			System.out.print(node + " ");
			
			for (int neighbor : graph[node]) {
				if(!visited[neighbor])
				{
					visited[neighbor] = true;
					queue.add(neighbor);
				}
			}
				
		}
	}

}
