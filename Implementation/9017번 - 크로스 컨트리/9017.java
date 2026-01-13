import java.io.*;
import java.util.*;

public class Main
{
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
		int tc = Integer.parseInt(br.readLine());
		for (int i = 0; i < tc; i++) {
		    Map<Integer, Integer> cntMap = new HashMap<>();
		    int n = Integer.parseInt(br.readLine());
		    int[] rank = new int[n];
		    int maxTeamNum = 0;
		    
		    // 등수 입력
		    st = new StringTokenizer(br.readLine());
		    for (int j = 0; j < n; j++) {
		        int team = Integer.parseInt(st.nextToken());
		        cntMap.put(team, cntMap.getOrDefault(team, 0) + 1);
		        rank[j] = team;
		        maxTeamNum = Math.max(maxTeamNum, team);
		    }
		    
		    Map<Integer, Integer> scoreMap = new HashMap<>();
		    int[] fifth = new int[maxTeamNum + 1];
		    int[] playerCnt = new int[maxTeamNum + 1];
		    
		    int score = 1;
		    for (int r : rank) {
		        if (cntMap.get(r) == 6) {
		            int cnt = playerCnt[r]++;
		            if (cnt < 4) {
		                scoreMap.put(r, scoreMap.getOrDefault(r, 0) + score);
		            } else if (cnt == 4) {
		                fifth[r] = score;
		            }
		            
		            score++;
		        }
		    }
		    
		    int minScore = Integer.MAX_VALUE;
		    int ans = 0;
		    
		    for (int team : scoreMap.keySet()) {
		        int teamScore = scoreMap.getOrDefault(team, 0);
		        
		        if (minScore > teamScore) {
		            minScore = teamScore;
		            ans = team;
		        } else if (minScore == teamScore) {
		            if (fifth[team] < fifth[ans]) ans = team;
		        }
		    }
		    
		    StringBuilder sb = new StringBuilder();
		    sb.append(ans);
            
            System.out.println(sb.toString());		   
		}
	}
}
