import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		char[][] map = new char[n + 1][n + 1];
		
		for (int i = 0; i < n; i++) {
		    String str = br.readLine();
		    for (int j = 0; j < n; j++) {
		        map[i][j] = str.charAt(j);
		    }
		    map[i][n] = map[n][i] = 'X';
		}
		
		int x_cnt = 0;
		int y_cnt = 0;
		int x_tmp = 0;
		int y_tmp = 0;
		
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n - 1; j++) {
		        if (map[i][j] == '.' && map[i][j + 1] == '.' && map[i][j + 2] == 'X') {
		            x_cnt++;
		        }
		        if (map[j][i] == '.' && map[j + 1][i] == '.' && map[j + 2][i] == 'X') {
		            y_cnt++;
		        }
		    }
		}
		
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n - 1; j++) {
		        
		    }
		}
		
		System.out.println(x_cnt + " " + y_cnt);
	}
}