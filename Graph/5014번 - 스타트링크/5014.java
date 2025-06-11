import java.io.*;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    static int f, s, g, u, d;
    static int[] vis;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        f = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());
        u = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        br.close();

        vis = new int[f + 1];
        Arrays.fill(vis, (int)1e9);
        solve();
    }

    public static void solve() {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(s);
        vis[s] = 0;

        while(!q.isEmpty()) {
            int cur = q.poll();
            int nxt = cur + u, pre = cur - d;

            if(nxt <= f && vis[nxt] > vis[cur] + 1) {
                vis[nxt] = vis[cur] + 1;
                q.add(nxt);
            }
            if(pre > 0 && vis[pre] > vis[cur] + 1) {
                vis[pre] = vis[cur] + 1;
                q.add(pre);
            }
        }

        System.out.println(vis[g] != 1e9 ? vis[g] : "use the stairs");
    }
}