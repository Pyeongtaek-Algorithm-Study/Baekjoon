import java.io.*;
import java.util.*;

public class Main
{
    static int n, e;
    static boolean[] vis;
    static boolean[][] computers;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        e = Integer.parseInt(br.readLine());
        vis = new boolean[n + 1];
        computers = new boolean[n + 1][n + 1];

        StringTokenizer st;
        for(int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            computers[a][b] = computers[b][a] = true;
        }

        br.close();
    }

    public static void solve() {
        System.out.println(dfs(1, 0));
    }

    private static int dfs(int i, int cnt) {
        vis[i] = true;

        for(int j = 1; j <= n; j++) {
            if(!vis[j] && computers[i][j]) {
                vis[j] = true;
                cnt = dfs(j, cnt + 1);
            }
        }

        return cnt;
    }
}