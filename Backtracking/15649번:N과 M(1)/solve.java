import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static boolean[] visit;
	static int[] arr;
	
	private static void DFS(int n, int m, int depth) {
		if (depth == m) {
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
			return;
		}
	 
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				arr[depth] = i + 1;
				DFS(n, m, depth + 1);
				visit[i] = false;
			}
		}
		return;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		visit = new boolean[n];
		arr = new int[m];
		
		DFS(n, m, 0);
	}

}
