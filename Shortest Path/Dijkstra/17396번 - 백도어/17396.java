import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main
{
    static class Node {
        int idx;
        long cost;
        
        public Node(int idx, long cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }
    
    static long MAX_VALUE = Long.MAX_VALUE;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		boolean[] isShow = new boolean[n + 1];
		ArrayList<Node>[] graph = new ArrayList[n + 1];
		
		// 보여지는 분기점 저장
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
		    graph[i] = new ArrayList<Node>();
		    
		    if (Integer.parseInt(st.nextToken()) == 1) {
		        isShow[i] = true;
		    }
		}
		
		for (int i = 0; i < m; i++) {
		    st = new StringTokenizer(br.readLine());
		    
		    int from = Integer.parseInt(st.nextToken());
		    int to = Integer.parseInt(st.nextToken());
		    int cost = Integer.parseInt(st.nextToken());
		    
		    graph[from].add(new Node(to, cost));
		    graph[to].add(new Node(from, cost));
		}
		
		long dist = dijkstra(n, graph, isShow);
		
		System.out.println(dist == Long.MAX_VALUE ? "-1" : dist);
	}
	
	private static long dijkstra(int n, ArrayList<Node>[] graph, boolean[] isShow) {
	    PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1.cost, o2.cost));
	    
	    long[] dist = new long[n + 1];
	    for (int i = 0; i < n; i++) {
	        dist[i] = MAX_VALUE;
	    }
	    
	    dist[0] = 0;
	    pq.add(new Node(0, 0));
	    
	    while (!pq.isEmpty()) {
	        Node curNode = pq.poll();
	        
	        if (curNode.idx == n - 1) {
	            break;
	        }
	        if (curNode.cost > dist[curNode.idx]) {
	            continue;
	        }
	        
	        for (int i = 0; i < graph[curNode.idx].size(); i++) {
	            Node nxtNode = graph[curNode.idx].get(i);
	            
	            // 넥서스까지 가기 위한 예외 처리
	            if (isShow[nxtNode.idx] && nxtNode.idx != n - 1) {
	                continue;
	            }
	            
	            if (dist[nxtNode.idx] > dist[curNode.idx] + nxtNode.cost) {
	                dist[nxtNode.idx] = dist[curNode.idx] + nxtNode.cost;
	                pq.offer(new Node(nxtNode.idx, dist[nxtNode.idx]));
	            }
	        }
	    }
	    
	    return dist[n - 1];
	}
}