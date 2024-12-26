import java.io.IOException;
import java.util.Scanner;


public class B_6603 {

	static int[] arr = new int[49];
	static int[] output = new int[6];
	
	public static void main(String[] args) throws IOException  {
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            dfs(arr, output, 0, 0, n);
            System.out.println();
        }
        

	}
	
	public static void dfs(int[] arr, int[] output, int start, int depth, int n) {
        if (depth == 6) {
            for (int i = 0; i < 6; i++) {
                System.out.print(output[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = start; i < n; i++) {
            output[depth] = arr[i];
            dfs(arr, output, i + 1, depth + 1, n);
        }
    }

}
