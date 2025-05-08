import java.util.Scanner;

public class Main {

	static int[][][] dp = new int[21][21][21];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();

			if(a == -1 && b == -1 && c == -1) break;

			System.out.printf("w(%d %d %d) = %d\n", a, b, c, w(a, b, c));
		}

		sc.close();
	}

	static int w(int a, int b, int c) {
		if(a <= 0 || b <= 0 || c <= 0) {
			return 1;
		}
		else if(a > 20 || b > 20 || c > 20) {
			return w(20, 20, 20);
		}

		if(dp[a][b][c] != 0) return dp[a][b][c];

		if(a < b && b < c) {
			dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		}
		else {
			dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		}

		return dp[a][b][c];
	}
}
