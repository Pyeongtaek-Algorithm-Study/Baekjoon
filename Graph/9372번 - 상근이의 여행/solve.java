import java.io.*;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class Num9372 {
	static boolean[] visit;
	static int[][] arr;
	static int n, m, count;
	
	private static void BFS() {
		Queue<Integer> queue = new LinkedList<Integer>();
		visit[1] = true;
		queue.add(1);
		while(!queue.isEmpty()) {
			count++;
			int vertex = queue.poll();
			for (int i = 1; i <= n; i++) {
				if(arr[vertex][i] != 0 && !visit[i]) {
					visit[i] = true;
					queue.add(i);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			count = 0;
			arr = new int[n+1][n+1];
			visit = new boolean[n+1];
			
			for (int j = 0; j < m; j++) {
				st = new StringTokenizer(br.readLine(), " ");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				arr[a][b] = 1;
				arr[b][a] = 1;
			}
			BFS();
			System.out.println(count - 1);
		}
	}
	
}
