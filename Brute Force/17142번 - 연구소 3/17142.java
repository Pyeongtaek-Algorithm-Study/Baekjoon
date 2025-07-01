import java.io.*;
import java.util.*;

public class Main {
    static final int INF = (int) 1e9;
    static final int LIM = 51;
    static int[] dx = {0, -1, 0, 1};
    static int[] dy = {-1, 0, 1, 0};

    static int n, m;
    static int[][] lab = new int[LIM][LIM];
    static int[][] visited = new int[LIM][LIM];
    static ArrayList<int[]> coor = new ArrayList<>();
    static int virusCount = 0;
    static int ans = INF;
    static ArrayList<Integer> selected = new ArrayList<>();

    static void dfsCombination(int depth, int start) {
        if (depth == m) {
            ans = Math.min(ans, bfs());
            return;
        }
        for (int i = start; i < virusCount; i++) {
            selected.add(i);
            dfsCombination(depth + 1, i + 1);
            selected.remove(selected.size() - 1);
        }
    }

    static int bfs() {
        Queue<int[]> Q = new LinkedList<>();
        for (int[] row : visited) Arrays.fill(row, -1);
        int spreadTime = 0;

        for (int idx : selected) {
            int[] p = coor.get(idx);
            Q.offer(new int[]{p[0], p[1]});
            visited[p[0]][p[1]] = 0;
        }

        while (!Q.isEmpty()) {
            int[] cur = Q.poll();
            int x = cur[0], y = cur[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (lab[nx][ny] == 1 || visited[nx][ny] != -1) continue;

                visited[nx][ny] = visited[x][y] + 1;
                if (lab[nx][ny] == 0) spreadTime = Math.max(spreadTime, visited[nx][ny]);
                Q.offer(new int[]{nx, ny});
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (lab[i][j] == 0 && visited[i][j] == -1)
                    return INF;

        return spreadTime;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                lab[i][j] = Integer.parseInt(st.nextToken());
                if (lab[i][j] == 2) {
                    coor.add(new int[]{i, j});
                    virusCount++;
                }
            }
        }

        dfsCombination(0, 0);

        System.out.println(ans != INF ? ans : -1);
    }
}
