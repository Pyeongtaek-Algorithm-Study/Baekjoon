import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[] score;
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		score = new int[n];
		
		for (int i = 0; i < n; i++) {
			score[i] = Integer.parseInt(br.readLine());
		}
		
		solve();
	}
	
	public static void solve() {
		Arrays.sort(score);
		long ans = 0;
		
		for (int i = 1; i <= n; i++) {
			ans += Math.abs(i - score[i - 1]);
		}
		
		System.out.println(ans);
	}
}
