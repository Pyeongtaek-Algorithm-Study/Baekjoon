import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static Set<String> setStr = new HashSet<>();
    static List<String> insStr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            setStr.add(br.readLine());
        }
        for (int i = 0; i < m; i++) {
            insStr.add(br.readLine());
        }
    }

    static void solve() {
        int ans = 0;

        for (String s : insStr) {
            if (setStr.contains(s)) ans++;
        }

        System.out.println(ans);
    }
}