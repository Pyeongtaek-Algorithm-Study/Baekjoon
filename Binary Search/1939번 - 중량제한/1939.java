import java.io.*;
import java.util.*;

public class Main {

    static final int LIM = 100001;
    static boolean[] visited = new boolean[LIM];
    
    // 도달 가능한지 확인하는 함수
    public static boolean bfs(int depart, int arrive, int val, List<int[]>[] path) {
        Arrays.fill(visited, false);
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(depart);
        visited[depart] = true;
        
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            
            if (cur == arrive) {
                return true;
            }
            
            for (int[] p : path[cur]) {
                int nxt = p[0];
                int weight = p[1];
                
                if (weight < val || visited[nxt]) continue;
                visited[nxt] = true;
                queue.offer(nxt);
            }
        }
        
        return false;
    }

    public static void solve(int n, int m, List<int[]>[] path, int fac_1, int fac_2) {
        int res = 0;
        int st = Integer.MAX_VALUE, end = -1;

        // 도로의 하중을 견딜 수 있는 최대, 최소 무게
        for (int i = 1; i <= n; i++) {
            for (int[] p : path[i]) {
                st = Math.min(st, p[1]);
                end = Math.max(end, p[1]);
            }
        }
        
        while (st <= end) {
            int mid = (st + end) / 2;
            
            if (bfs(fac_1, fac_2, mid, path)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        List<int[]>[] path = new List[LIM];
        for (int i = 1; i <= n; i++) {
            path[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            path[a].add(new int[] {b, c});
            path[b].add(new int[] {a, c});
        }
        
        st = new StringTokenizer(br.readLine());
        int fac_1 = Integer.parseInt(st.nextToken());
        int fac_2 = Integer.parseInt(st.nextToken());
        
        solve(n, m, path, fac_1, fac_2);
    }
}
