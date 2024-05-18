### 4485번: 녹색 옷을 입은 애가 젤다지?

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/4485)

> 풀이는 2개 방식 BFS, Dijkstra있지만 Dijkstra를 기준으로 설명 ( BFS방식은 스스로 해석해봅시다. )

**문제 조건**
- 주인공 링크는 N X N 크기의 제일 왼쪽 위(0,0)에 존재  
_젤다 시리즈에서 초록 옷을 입은 주인공은 링크이고, 젤다는 공주라고 한다.ㅋㅋ_
- (N-1,N-1)까지 도달할 때 까지 각 칸에는 도둑루피가 존재하고 그 크기만큼 소지름을 잃는다.
- 링크는 잃는 금액을 최소로 목적지까지 도달해야 하며, 한 번에 상하좌우에서 인접한 1칸씩만 이동할 수 있다. 
- N = 0 일때는 종료

**출력**  
- 각 케이스마다 잃는 소지금의 값을 최소값을 "Problem [n번째]: [잃는 소지금]"

### 풀이
1. 


> priority_queue의 인자에 3개의 변수가 저장되야 해야 한번 struct로 구성해서 해봤지만, 문제는 통과하지만 속도가 느림. _(pair: 4ms, struct: 12ms)_

### 핵심 코드

<details>
<summary>코드 보기</summary>

```
void dijkstra() {
    // 연속된 3개의 변수를 한번에 저장하는 그런 것은 struct로 구성하면 가능
    // pq가 길다면은 처음부분에 음수로 저장하기.
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({board[0][0], {0, 0}});
    vis[0][0] = board[0][0];
    
    while(!pq.empty()) {
        int cost = pq.top().X;
        int x = pq.top().Y.X;
        int y = pq.top().Y.Y;
        pq.pop();
        
        if(cost > vis[x][y]) continue; 
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int ncost = cost + board[nx][ny];
            if ( vis[nx][ny] <= ncost) continue;
            vis[nx][ny] = ncost;
            pq.push(make_pair(vis[nx][ny], make_pair(nx, ny)));
        }
    }
}
```


</details>