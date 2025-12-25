import java.io.*;
import java.util.*;

public class Main {
	static int m;
	static boolean[] check;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		m = Integer.parseInt(br.readLine());
		check = new boolean[21];
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			
			String cmd = st.nextToken();
			int x = 0;
			if (st.hasMoreTokens()) {
				x = Integer.parseInt(st.nextToken());
			}
			
			if (cmd.equals("add")) {
				check[x] = true;
			}
			else if (cmd.equals("remove")) {
				check[x] = false;
			}
			else if (cmd.equals("check")) {
				sb.append(check[x] ? 1 : 0)
					.append("\n");
			}
			else if (cmd.equals("toggle") ) {
				check[x] = !check[x];
			}
			else if (cmd.equals("all")) {
				Arrays.fill(check, true);
			}
			else {
				Arrays.fill(check, false);
			}
		}
		
		System.out.println(sb.toString());
	}

}
