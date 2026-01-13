import java.io.*;
import java.util.*;

public class Main
{
    static int n;
    static int[][] paper;
    static int zeroCnt = 0, plusCnt = 0, minusCnt = 0;
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    n = Integer.parseInt(br.readLine());
	    paper = new int[n + 1][n + 1];
	    
	    for (int i = 1; i <= n; i++) {
	        st = new StringTokenizer(br.readLine());
	        
	        for (int j = 1; j <= n; j++) {
	            paper[i][j] = Integer.parseInt(st.nextToken());
	        }
	    }
	        
	    solve();
	}
	
	public static void solve() {
	    recur(1, 1, n);
	    
	    StringBuilder sb = new StringBuilder();
	    sb.append(minusCnt + "\n")
	        .append(zeroCnt + "\n")
	        .append(plusCnt);
	    
	    System.out.println(sb.toString());
	}
	
	public static void recur(int r, int c, int len) {
	    // 현재 종이 칸에서 모두 같은 값인지 확인
	    if (sameCheck(r, c, len)) {
            return;
	    }
	    
        int divideLen = len / 3;
        for (int i = r; i < r + len; i += divideLen) {
            for (int j = c; j < c + len; j += divideLen) {
                recur(i, j, divideLen);
            }
        }
	}
	
	public static boolean sameCheck(int r, int c, int len) {
	    
	    for (int i = r; i < r + len; i++) {
	        for (int j = c; j < c + len; j++) {
	            if (paper[i][j] != paper[r][c]) {
    	            return false;
	            }
	        }
	    }
	    
	    if (paper[r][c] == -1) {
            minusCnt++;
        } else if (paper[r][c] == 0) {
            zeroCnt++;
        } else {
            plusCnt++;
        }
	    
	    return true;
	}
}
