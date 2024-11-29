### 1260번: DFS와 BFS

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1260)
2. **도움 블로그** : [바로가기](https://velog.io/@falling_star3/%EB%B0%B1%EC%A4%80Python-1260%EB%B2%88-DFS%EC%99%80BFS)

**문제 조건**
- 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

**출력**  
- 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

### 풀이

1. 인접 리스트에 간선 정보를 입력받는다.
2. 방문한 노드를 기록하는 배열을 만듬
3. DFS는 깊이 우선 탐색이므로 재귀함수를 이용하여 방문하지 않은 노드들을  탐색
4. 방문 기록을 초기화 하고 BFS는 넓이 우선 탐색이므로 큐를 이용하여 방문하지 않은 노드들을 탐색

### 핵심 코드

```
public static void dfs(int node)
	{
		visited[node] = true;
		System.out.print(node + " ");
		
		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				dfs(neighbor);
			}
		}
			
	}

public static void bfs(int start)
	{
		Queue<Integer> queue = new LinkedList<>();
		visited[start] = true;
		queue.add(start);
		
		while (!queue.isEmpty()) {
			int node = queue.poll();
			System.out.print(node + " ");
			
			for (int neighbor : graph[node]) {
				if(!visited[neighbor])
				{
					visited[neighbor] = true;
					queue.add(neighbor);
				}
			}
				
		}
	}

```


### 후기
그래프 문제를 처음 풀어 보니 내가 생각한거랑 많이 달랐다. 패턴을 파악하게 된다면 생각보다 쉬워질것 같다.
