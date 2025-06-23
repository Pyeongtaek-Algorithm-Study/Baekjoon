import java.io.*;
import java.util.*;

public class Main {
    static final int INF = (int) 1e9;
    static int n, m;
    static int[] friends = new int[3];
    static List<int[]>[] roads = new ArrayList[100001];
    static int[][] minDist = new int[3][100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; i++) {
            friends[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++) {
            roads[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            roads[d].add(new int[]{e, l});
            roads[e].add(new int[]{d, l});
        }

        solve();
    }

    static void dijkstra(int idx, int start) {
        Arrays.fill(minDist[idx], 0, n + 1, INF);

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, start});
        minDist[idx][start] = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int dist = cur[0];
            int now = cur[1];

            if (minDist[idx][now] < dist) continue;

            for (int[] next : roads[now]) {
                int to = next[0];
                int cost = dist + next[1];

                if (minDist[idx][to] > cost) {
                    minDist[idx][to] = cost;
                    pq.offer(new int[]{cost, to});
                }
            }
        }
    }

    static void solve() {
        for (int i = 0; i < 3; i++) {
            dijkstra(i, friends[i]);
        }

        int ans = -1;
        int maxDist = 0;

        for (int i = 1; i <= n; i++) {
            if (i == friends[0] || i == friends[1] || i == friends[2]) continue;

            int minFriendDist = Math.min(minDist[0][i], Math.min(minDist[1][i], minDist[2][i]));

            if (minFriendDist > maxDist) {
                maxDist = minFriendDist;
                ans = i;
            }
        }

        System.out.println(ans);
    }
}
