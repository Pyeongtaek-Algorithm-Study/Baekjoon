import java.io.*;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main {
	static int n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		BigInteger[][] dp = new BigInteger[101][101];
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if(j == 0 || j == i) dp[i][j] = BigInteger.ONE;
				else dp[i][j] = dp[i - 1][j].add(dp[i - 1][j - 1]);
			}
		}
		System.out.println(dp[n][m]);
	}

}
