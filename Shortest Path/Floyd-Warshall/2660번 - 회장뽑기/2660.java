import java.io.*;
import java.util.*;

public class Main
{
    static final int INF = 987654321;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[][] map = new int[n + 1][n + 1];
		
		for (int i = 0; i < n; i++) {
		    Arrays.fill(map[i], INF);
		    map[i][i] = 0;
		}
		
		String line;
		while (!(line = br.readLine()).equals("-1 -1")) {
		    StringTokenizer st = new StringTokenizer(line);
		    int a = Integer.parseInt(st.nextToken()) - 1;
		    int b = Integer.parseInt(st.nextToken()) - 1;
		    map[a][b] = 1;
		    map[b][a] = 1;
		}

        // 모든 노드 간의 각 최소 거리 구하기
		for (int k = 0; k < n; k++) {
		    for (int i = 0; i < n; i++) {
		        for (int j = 0; j < n; j++) {
		            if (map[i][j] > map[i][k] + map[k][j]) {
		                map[i][j] = map[i][k] + map[k][j];
		            }
		        }
		    }
		}
		
		int minValue = INF;
		int[] distance = new int[n + 1];
		for (int i = 0; i < n; i++) {
		    int status = 0;
		    for (int j = 0; j < n; j++) {
		        status = Math.max(status, map[i][j]);
		    }
		    distance[i] = status;
		    minValue = Math.min(minValue, status);
		}
		
		int cnt = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
		    if (distance[i] == minValue) {
		        cnt++;
		        sb.append((i + 1)+ " ");
		    }
		}
		
		System.out.println(minValue + " " + cnt);
		System.out.println(sb.toString());
	}
}