import java.io.*;
import java.util.*;

public class Main {
    static final int INF = (int) 1e9;
    static final int LIM = 501;

    static int novel;
    static int[] pages = new int[LIM];
    static int[] sum = new int[LIM];
    static int[][] dp = new int[LIM][LIM];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        while (tc-- > 0) {
            novel = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= novel; i++) {
                pages[i] = Integer.parseInt(st.nextToken());
            }

            // dp, sum 초기화
            for (int i = 0; i <= novel; i++) {
                sum[i] = 0;
                Arrays.fill(dp[i], 0);
            }

            solve();
        }
    }
    
    static void solve() {
        for (int i = 1; i <= novel; i++) {
            sum[i] = sum[i - 1] + pages[i];
        }

        for (int k = 1; k < novel; k++) { // k - 1 구간
            for (int st = 1; st + k <= novel; st++) { // 시작점
                int end = st + k; // 끝점
                dp[st][end] = INF;

                int sum_page = sum[end] - sum[st - 1];
                for (int mid = st; mid < end; mid++) {
                    dp[st][end] = Math.min(dp[st][end],
                                           dp[st][mid] + dp[mid + 1][end] + sum_page);
                }
            }
        }

        System.out.println(dp[1][novel]);
    }
}
