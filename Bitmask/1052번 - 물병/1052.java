import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int k;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
    }

    static void solve() {
        int ans = 0;
        while (countBits(n + ans) > k) {
            ans++;
        }
        System.out.println(ans);
    }

    static int countBits(int x) {
        int cnt = 0;
        while (x != 0) {
            if ((x & 1) == 1) cnt++;
            x >>= 1;
        }
        return cnt;
    }
}