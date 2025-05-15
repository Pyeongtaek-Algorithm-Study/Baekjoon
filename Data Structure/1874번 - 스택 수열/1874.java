import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] nums;
    
    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
    
    static void input() throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            nums = new int[n];
            
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(br.readLine());
            }
        }
    }
    
    static void solve() {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>();
        int cur = 1;
        
        for (int num : nums) {
            while (cur <= num) {
                stack.push(cur++);
                sb.append("+\n");
            }
            
            if(stack.peek() == num) {
                stack.pop();
                sb.append("-\n");
            } else {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println(sb.toString());
    }
}