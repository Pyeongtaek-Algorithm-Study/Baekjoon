import java.util.*;
import java.io.*;

public class Main
{
    static int LIM = 1001;
    static int[][] graph = new int[LIM][LIM];
    static boolean[] visited = new boolean[LIM];
    static int n, m;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a][b] = graph[b][a] = 1;
        }
    }

    static void solve() {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                ans++;
            }
        }

        System.out.println(ans);
    }

    static void dfs(int i) {
        if (visited[i]) {
            return;
        }
        else {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    dfs(j);
                }
            }
        }
    }
}