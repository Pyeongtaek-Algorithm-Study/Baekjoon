### 문제 제목
* * *
2606번: 바이러스
### 링크
* * *
* <https://www.acmicpc.net/problem/2606>
### 문제 설명
* * *
컴퓨터의 수와 컴퓨터의 번호가 주어진다.

그리고 서로 연결되어 있는 번호 쌍이 주어진다.

1번 컴퓨터에서 바이러스가 걸렸다면 연결되어 있는 모든 컴퓨터들이 바이러스에 걸리게 되는데 그때 그 컴퓨터의 수를 구하면 된다.
### 풀이
* * *
처음에는 그냥 연결된거 찾는 것이므로 bfs를 이용하면 된다고 생각했는데, 생각해 보니 dfs도 모든 연결된 자식 노드들을 구할 수 있으니 연결 갯수를 찾을때는
dfs와 bfs를 모두 활용해도 된다.
bfs 코드는
<pre>
  <code>
from collections import deque
import sys
def bfs(v, graph, visited):
    q = deque([v])
    while q:
        n = q.popleft()
        for i in graph[n]:
            if visited[i] == 0:
                visited[i] = 1
                q.append(i)
    return sum(visited) - 1

n = int(input())
s = int(input())
visited = [0] * (n + 1)
graph = [[] for i in range(n + 1)]

for i in range(s):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
print(bfs(1, graph, visited))

    
  </code>
</pre>
dfs 코드는
<pre>
  <code>

import sys
def dfs(graph, v, visited):
    visited.append(v)
    for i in graph[v]:
        if i not in visited:
            dfs(graph, i, visited)

    return visited


a=int(sys.stdin.readline())
b=int(sys.stdin.readline())
graph=[[] for i in range(a+1)]
for _ in range(b):
    x,y=map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)

visited=[]
print(len(dfs(graph,1,visited))-1)

  </code>
</pre>

bfs는 큐를 이용해서 모든 자식 노드들을 차례대로 돌아가게끔 하고, 자식 노드가 방문 될때마다 visited에 1을 추가해준다.<br>
큐가 다 비었으면 자식 노드들은 이제 없는거니깐 방문노드의 sum한값에 -1을 해줘야된다.<br>
-1을 해주는 이유는 1번 노드에 방문할때 1이 추가 되었는데, 1은 원래 바이러스에 걸린 것이니 -1을 해주면 된다.<br>
dfs는 재귀를 이용하였는데 자식 노드를 부를때마다 dfs함수를 다시 불러주어, visit에 추가해주면된다. 자식 노드가 불러질때마다 재귀를 부른것이니<br>
자식 노드가 없으면 return해주면 된다.<br>
마찬가지로 sum한 값에 -1을 해주면 된다.<br>
공통 코드에서 그래프를 추가하는 방식에 대해 말해보자면, 쌍을 입력받을때 서로가 서로 연결되어 있는 것이므로 만약, 1이 2번과 연결되어 있다면,<br>
1<->2 이렇게 이중 연결 리스트를 만들어야 줘야된다.<br>
graph[1]=[2], grpah[2]=[1] 이런식으로 만들어야 되므로,<br>
애초에 입력을 받을때 map함수로 두 수를 x,y에 입력해주고, grpah[x]엔 y값을 추가해주고, graph[y]엔 x값을 추가해주면 이중 연결 리스트를 구현할수 있다.<br>

