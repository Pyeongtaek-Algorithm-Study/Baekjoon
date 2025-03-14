### 1240번: 노드사이의 거리

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1240)
2. **도움 블로그** : 

**문제 조건**
- N개의 노드로 이루어진 트리가 있으며 두 노드 사이에 거리가 존재

**출력**  
- M개의 줄에 차례대로 입력받은 **두 노드 사이의 거리**를 출력

### 풀이
1. N-1 개의 간선을 입력받으며, 임의의 두 노드 사이에 갈 수 있는 길은 1개
2. 입력 받은 두 노드마다 _DFS_ 또는 _BFS_ 를 통해서 **두 노드 사이의 거리**를 찾음
3. 찾은 거리를 매 단계마다 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void dfs(int st, int end, int weight) {
    vis[st] = 1;
    
    if(st == end) {
        cout << weight << '\n';
        return;
    }
    
    for(int i = 0; i < v[st].size(); i++) {
        int n_st = v[st][i].X;
        int n_weight = v[st][i].Y + weight;
        
        if(!vis[n_st]) dfs(n_st, end, n_weight);
    }
}
```
- 현재 노드 위치인 `st`, 도착 위치인 `end`, 현재까지의 거리인 `weight`인 `dfs()` 선언
- `vis[]`을 통해 현재 노드인 `st` 위치에 방문 처리
- 만일 현재 위치가, 도착 위치인 `end` 값에 도착할 경우 `weight` 값을 출력 후 종료
- 현재 위치에서 다음 노드로 방문할 수 있는 **간선**들이 있을 때 다음 노드인 `n_st`, 다음 노드까지의 거리인 `n_weight`를 계산
- 다음 노드가 방문하지 않을 경우 **탐색** 진행
- 위 과정들을 반복하여 최종적으로 `end` 위치인 노드를 찾을 때까지 반복
</details>

### 후기
- 