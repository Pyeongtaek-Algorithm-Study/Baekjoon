import java.io.*;
import java.util.*;

public class Main {
    static final int LIM = 20001;
    static final int RED = 2;
    static final int BLUE = 3;

    static int tc;
    static int v, e;
    static List<Integer>[] edges = new ArrayList[LIM];
    static int[] color = new int[LIM];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < LIM; i++) {
            edges[i] = new ArrayList<>();
        }

        while (tc-- > 0) {
            input(br);
            solve();
        }
    }

    static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        
        // 이전 입력값 초기화
        Arrays.fill(color, 0);
        for (int i = 1; i <= v; i++) {
            edges[i].clear();
        }

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            edges[a].add(b);
            edges[b].add(a);
        }
    }
    
    static void solve() {
        boolean isBipartite = true;

        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (!bfs(i)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        System.out.println(isBipartite ? "YES" : "NO");
    }

    static boolean bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        color[start] = RED;

        while (!q.isEmpty()) {
            int cur = q.poll();
            int nextColor = (color[cur] == RED) ? BLUE : RED;

            for (int next : edges[cur]) {
                if (color[next] == 0) {
                    color[next] = nextColor;
                    q.add(next);
                } else if (color[next] == color[cur]) {
                    return false;
                }
            }
        }
        return true;
    }
}
