import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static List<int[]> bridges = new ArrayList<>();
    static int[] parents;
    
    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
    
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        parents = new int[n + 1];
        
        for (int i = 0; i < n - 2; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bridges.add(new int[]{a, b});
        }
        
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }
        
        br.close();
    }
    
    static void solve() {
        for (int[] bridge : bridges) {
            int a = bridge[0];
            int b = bridge[1];
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            
            union(a, b);
        }
        
        for (int i = 2; i <= n; i++) {
            if (find(1) != find(i)) {
                System.out.println(1 + " " + i);
                break;
            }
        }
    }
    
    static int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }
    
    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parents[b] = a;
    }
}