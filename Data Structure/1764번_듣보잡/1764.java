/**
 * 1764번 : 듣보잡
 * 카테고리 : Data_Struction
 * 
 */

import java.io.*;
import java.util.*;

public class Main
{
    private static int n, m;
    private static Set<String> listenName;
    private static List<String> readName;
    
	public static void main(String[] args) throws IOException {
		
	    input();
	    solve();
		
	}
	
	private static void input() throws IOException {
	    
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    listenName = new HashSet<>();
	    readName = new ArrayList<>();
	    
	    st = new StringTokenizer(br.readLine());
	    
	    n = Integer.parseInt(st.nextToken());
	    m = Integer.parseInt(st.nextToken());
	    
	    for (int i = 0; i < n; i++) {
	        
	        String name = br.readLine();
	        listenName.add(name);
	    }
	    
	    for (int i = 0; i < m; i++) {
	        
	        String name = br.readLine();
	        readName.add(name);
	    }
	    
	    br.close();
	}
	
	private static void solve() {
	    
	    // 사전 순으로 오름차순 정렬
	    readName.sort(Comparator.naturalOrder());
	    
	    List<String> answerName = new ArrayList<>();
	    
	    // 보도 못한 이름을 기준으로 듣보 못한 이름이 있는지 확인
	    for (String name : readName) {
	        
	        if (listenName.contains(name)) {
	            answerName.add(name);
	        }
	    }
	    
	    // 정답 출력
	    System.out.println(answerName.size());
	    
	    for (String name : answerName) {
	        
	        System.out.println(name);
	    }
	}
	
}