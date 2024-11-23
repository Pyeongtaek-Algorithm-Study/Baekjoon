import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B_2293 {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        
        int n = Integer.parseInt(stringTokenizer.nextToken());
        int k = Integer.parseInt(stringTokenizer.nextToken());
        
        int[] coin = new int[n];
        int[] dp = new int[k + 1];
        
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            coin[i] = Integer.parseInt(bufferedReader.readLine());
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= k; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        
        System.out.println(dp[k]);
    }
}
