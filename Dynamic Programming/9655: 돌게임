import java.io.*;

public class Num9655 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		boolean[] dp = new boolean[n + 1];
		
		// true일 경우 상근의 승리, false일 경우 창영의 승리
		dp[1] = true;
		if (n >= 3) dp[3] = true;
		
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] ? false : true;	// dp[i] = !dp[i - 1];
		}
		
		if (dp[n]) System.out.println("SK");
		else System.out.println("CY");
	}
	
}
