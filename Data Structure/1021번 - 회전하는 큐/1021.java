import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
	
	public static void main(String[] args) throws IOException {
//		System.setIn(new FileInputStream("src/input.txt"));
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int res = 0;
		
		LinkedList<Integer> dq = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			dq.offer(i);
		}
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			int findNum = Integer.parseInt(st.nextToken());
			
			while (dq.getFirst() != findNum) {
				if (dq.indexOf(findNum) <= (dq.size() / 2)) {
					dq.addLast(dq.pollFirst());
				}
				else {
					dq.addFirst(dq.pollLast());
				}
				
				res++;
			}
			
			dq.poll();
		}
		
		System.out.println(res);
	}
		
}
