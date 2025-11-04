import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main
{
    static int n;
    static int m;
    static int r;
    static int c;
    static int d;
    static int[][] room;
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int cnt = 1;
    
	public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        
        room = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                room[i][j] = sc.nextInt();
            }
        }
        
        dfs(r, c, d);
        System.out.println(cnt);
	}
	
	private static void dfs(int x, int y, int dir) {
	    room[x][y] = -1;
	    
	    for (int i = 0; i < 4; i++) {
	        // 반시계 방향임으로 +3
	        dir = (dir + 3) % 4;
	        
	        int nx = x + dx[dir];
	        int ny = y + dy[dir];
	        if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0) {
	            cnt++;
	            dfs(nx, ny, dir);
	            return;
	        }
	    }
	    
	    int backDir = (dir + 2) % 4;
	    int bx = x + dx[backDir];
	    int by = y + dy[backDir];
	    if (bx >= 0 && bx < n && by >= 0 && by < m && room[bx][by] != 1) {
	        dfs(bx, by, dir);
	    } 
	}
}