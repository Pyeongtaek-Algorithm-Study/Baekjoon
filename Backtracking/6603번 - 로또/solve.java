import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int k;
	static boolean[] visit;
	static int[] arr;
	static int[] S;
	
	private static void DFS(int start, int depth) {
		if (depth == 6) {
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
			return;
		}
	 
		for (int i = start; i < k; i++) {
			if (!visit[i]) {
				visit[i] = true;
				arr[depth] = S[i];
				DFS(i, depth + 1);
				visit[i] = false;
			}
		}
		return;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			if (k == 0) break;
			S = new int[k];
			for (int i = 0; i < k; i++) {
				S[i] = Integer.parseInt(st.nextToken());
			}
			
			visit = new boolean[k];
			arr = new int[6];
			
			DFS(0, 0);
			System.out.println();
		}
	}

}
