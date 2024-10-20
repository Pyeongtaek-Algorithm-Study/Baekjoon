import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] parents;
    
    static int find(int x) {
        if(x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }
    
    static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if(x > y) parents[x] = y;
        else parents[y] = x;
    }
    
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        parents = new int[n + 1];
        for(int i = 1; i <= n; i++) parents[i] = i;
        
        for(int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++) {
                int num = Integer.parseInt(st.nextToken());
                if(num == 1) union(i, j);
            }
        }
        
        st = new StringTokenizer(br.readLine());
        int start = find(Integer.parseInt(st.nextToken()));
        boolean flag = true;
        
        for(int i = 1; i < m; i++) {
            int num = find(Integer.parseInt(st.nextToken()));
            if(start != num) {
                flag = false;
                break;
            }
        }
        System.out.println(flag ? "YES" : "NO");
    }
}
