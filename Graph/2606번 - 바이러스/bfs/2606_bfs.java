import java.io.*;
import java.util.*;

public class Main
{
    static int n, e, ans;
    static boolean[] vis;
    static List[] computers;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        e = Integer.parseInt(br.readLine());
        vis = new boolean[n + 1];
        computers = new List[n + 1];
        ans = 0;

        for(int i = 0; i <= n; i++) {
            computers[i] = new ArrayList<Integer>();
        }

        StringTokenizer st;
        for(int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            computers[a].add(b);
            computers[b].add(a);
        }

        br.close();
    }

    public static void solve() {
        bfs(1);
        System.out.println(ans - 1);
    }

    private static void bfs(int n) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(n);
        vis[n] = true;

        while(!queue.isEmpty()) {
            int cur = queue.poll();
            ans++;

            for(int i = 0; i < computers[cur].size(); i++) {
                int nxt = (Integer)computers[cur].get(i);
                if(vis[nxt]) continue;

                vis[nxt] = true;
                queue.add(nxt);
            }
        }
    }
}
