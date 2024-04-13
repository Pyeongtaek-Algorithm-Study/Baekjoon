import java.io.*;

public class Num9657 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		boolean[] dp = new boolean[n + 1];
		
		// true일 경우 상근의 승리, false일 경우 창영의 승리
		dp[1] = true;
		if (n >= 3) dp[3] = true;
		else if (n >= 4) dp[4] = true;
		
		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 1] && dp[i - 3] && dp[i - 4]) ? false : true;
		}
		
		System.out.println(dp[n] ? "SK" : "CY");
	}
	
}
