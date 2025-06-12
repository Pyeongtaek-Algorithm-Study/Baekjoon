import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static List<String> files = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < n; i++) {
            files.add(br.readLine());
        }
        
        solve();
    }
    
    static void solve() {
        TreeMap<String, Integer> extCnt = new TreeMap<>();
        
        for (String file : files) {
            String ext = file.substring(file.indexOf('.') + 1);
            extCnt.put(ext, extCnt.getOrDefault(ext, 0) + 1);
        }
        
        for (Map.Entry<String, Integer> entry : extCnt.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}