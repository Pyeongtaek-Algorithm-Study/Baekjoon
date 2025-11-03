import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int right = 0;
        int left = 0;
        List<Integer> trees = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            trees.add(Integer.parseInt(st.nextToken()));
            right = Math.max(right, trees.get(i));
        }
        
        int ans = 0;

        while(left <= right){
            int mid = (right + left) / 2;
            
            // sum의 값이 int형을 넘을 수 있음
            long sum = 0;
            
            for(int height : trees){
                if (height - mid > 0) {
                    sum += height - mid;
                }
            }

            if(sum >= m) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        System.out.println(ans);
    }
}
