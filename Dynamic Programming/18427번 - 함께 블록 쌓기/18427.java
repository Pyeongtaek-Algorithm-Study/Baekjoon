import java.io.*;
import java.util.*;

public class Main {
    static int n, m, h;
    static List<Integer>[] students;
    static int[][] dp;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        
        students = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            students[i] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                students[i].add(Integer.parseInt(st.nextToken()));
            }
        }
        
        dp = new int[n + 1][h + 1];
        
        solve();
    }
    
    static void solve() {
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= h; j++) {
                for (int block : students[i]) {
                    if (j >= block) {
                        dp[i][j] += dp[i - 1][j - block];
                        dp[i][j] %= 10007;
                    }
                }
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= 10007;
            }
        }
        
        System.out.println(dp[n][h]);
    }
}