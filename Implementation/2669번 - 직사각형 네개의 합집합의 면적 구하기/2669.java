import java.io.*;
import java.util.*;

public class Main
{
    static int[][] chk = new int[101][101];
    static int answer = 0;
    
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    int[] coor = new int[4];
	    for (int i = 0; i < 4; i++) {
	        st = new StringTokenizer(br.readLine());
	        for (int j = 0; j < 4; j++) {
	            coor[j] = Integer.parseInt(st.nextToken());
	        }
	       
	        for (int x = coor[0]; x < coor[2]; x++) {
	            for (int y = coor[1]; y < coor[3]; y++) {
	                chk[x][y] = 1;
	            }
	        }
	    }
	    
	    for (int i = 0; i < 101; i++) {
	        for (int j = 0; j < 101; j++) {
	            if (chk[i][j] == 1) answer++;
	        }
	    }
	    
	    System.out.println(answer);
	}
}