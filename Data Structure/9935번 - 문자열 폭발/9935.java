import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String reg = br.readLine();
        int regLen = reg.length();
        
        Stack<Character> st = new Stack<>();
        
        for (int i = 0; i < line.length(); i++) {
            st.push(line.charAt(i));
            
            if (st.size() >= regLen) {
                boolean flag = true;
                
                for (int j = 0; j < regLen; j++) {
                    if (st.get(st.size() - regLen + j) != reg.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                
                if (flag) {
                    for (int j = 0; j < regLen; j++) {
                        st.pop();
                    }
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (Character c : st) {
            sb.append(c);
        }
        
        System.out.println(sb.length() == 0 ? "FRULA" : sb.toString());
    }
}