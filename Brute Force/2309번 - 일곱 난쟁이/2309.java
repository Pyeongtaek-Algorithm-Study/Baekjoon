import java.io.*;
import java.util.*;

public class Main {
    static int[] dwarf = new int[9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            dwarf[i] = Integer.parseInt(br.readLine());
        }

        solve();
    }

    static void solve() {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            sum += dwarf[i];
        }

        int target = sum - 100;
        int x = -1, y = -1;

        for (int i = 0; i < 9; i++) {
            for (int j =  i + 1; j < 9; j++) {
                if (dwarf[i] + dwarf[j] == target) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1) break;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            if (i == x || i == y) continue;
            result.add(dwarf[i]);
        }

        Collections.sort(result);
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }
    }
}