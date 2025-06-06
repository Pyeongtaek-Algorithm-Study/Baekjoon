### 14942번: 개미

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14942)
2. **도움 블로그** : https://tech-interview.tistory.com/175

**문제 조건**
- 개미집은 1 ~ N 개의 방으로 각 방은 서로 굴을 통해 연결되게 구성하며, 그 중 **1번 방**은 지면에 바로 연결되어 있는 방
- 개미는 집짓기의 달인이기 때문에 불필요한 굴을 짓지 않으며, 굴을 타고 한 방에서 다른 방으로 갈 수 있는 경로는 **항상 존재하며 유일**
- 임의의 두 방 사이의 거리는 두 개의 방을 연결하는 경로를 구성하는 굴의 길이 합
- 겨울잠을 자던 개미들은 겨울잠에서 깨어나 지면으로 올라가 햇살을 보려고 1번 방으로 이동
- 하지만, 개미는 긴 겨울잠을 자느라 축적해 놓은 에너지가 적어서 1번 방에 도달하기 전에 모두 소모할 수 도 있음  
_(에너지가 0인 개미는 더 이상 움직일 수 없으며, 1번 방에 도착한 개미는 더 이상 움직이지 않음)_
- 현재 모든 방에는 개미가 한 마리씩 있고 각각의 개미는 각자 **축적된 에너지**를 가지고 있으며, 잠에서 깨어난 모든 개미는 1번 방을 향해 이동

**출력**  
- 각자의 방에 있던 개미가 자신이 축적한 에너지를 갖고 1번 방과 **가장 가까운 방의 번호**를 출력  
_가장 가까운 것은 번호가 아닌 깊이를 기준으로 말함_

### 풀이
1. 입력 받은 굴을 통해서 각자 방이 1번 방을 기준으로 얼마나 떨어져 있는지 확인
2. 방의 개수가 많고, 한 마리의 개미가 아닌 모든 개미들의 경우를 다 살펴봐야 함으로, 단순으로 이동하는 것은 _"시간초과"_ 발생
3. 따라서, 임의의 방에서 필요 에너지에 따라 한 번에 1번에 가깝게 **한 번에 이동**할 수 있는 그러한 배열 값을 생성 _Sparse Table_
4. 위에서 구한 배열 값을 이용하여 각 개미의 시작 방에서 에너지들을 소비하여 올라갈 수 있는 방들을 점프하면서 이동
5. 더 이상 에너지가 부족하거나, 이미 1번 방에 도착했을 경우 해당 **현재 방 위치**를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void dfs(int curNode, int preNode) {
    parents[curNode][0] = preNode;
    
    for(int i = 0; i < path[curNode].size(); i++) {
        int nxtNode = path[curNode][i].X;
        
        if(nxtNode != preNode) {
            dist[nxtNode][0] = path[curNode][i].Y;
            dfs(nxtNode, curNode);
        }
    }
}
```
- `dfs()`을 통해 1번 방에서 각각의 방들의 깊이를 체크하여 가까운지 값을 `parents[][]`에 저장
- `curNode` 는 현재(자식) 방을, `preNode`는 상위(부모) 방, `nxtNode`는 다음 탐색할 방을 나타냄
- `parents[i][j]`은 `i`번 방에서 `2^j` 번을 **이동**했을 때의 방을 나타냄
- `dist[][]`는 상위 방으로 이동하기 위한 **굴의 필요 에너지**를 나타내며 2^0의 위치에 값을 저장

```cpp
void sparse_table() {
    // i섬에서 2^j 이동했을 때의 필요 에너지와 상위 노드 값 테이블 저장
    for(int j = 1; j < LOG; j++) {
        for(int i = 1; i <= n; i++) {
            dist[i][j] = dist[i][j-1] + dist[parents[i][j-1]][j-1];
            parents[i][j] = parents[parents[i][j-1]][j-1];
        }
    }
    
    // 각각의 개미들이 가지고 있는 에너지로 도달할 수 있는 방 출력
    for(int i = 1; i <= n; i++) {
        int pos = i, energy = energys[i];
        for(int j = LOG - 1; j >= 0; j--) {
            if(parents[pos][j] != 0 && energy >= dist[pos][j]) {
                energy -= dist[pos][j];
                pos = parents[pos][j];
            }
        }
        cout << pos << '\n';
    }
}
```
- `sparse_table()`은 `parents[i][j]`와 `dist[i][j]`에 `i`번 방에서 `2^j`번 **이동한 방과 필요 에너지 값**을 할당하고, 각 개미들의 에너지를 갖고 도달할 수 있는 방을 출력하는 함수
- 각 1번 개미부터 `n`번 개미까지 자신의 에너지를 가지고 1번 방에 가까운 방에 도달할 수 있는 방을 찾음
- `pos`는 해당 개미가 있는 방을 나타내고, `energy`는 해당 개미가 가지고 있는 에너지를 나타냄
- `2^{LOG - 1}` 부터 `2^0` 까지 각각의 방에서 필요 에너지들을 소모해서 상위 방으로 올라감
- `parents[][]` 값이 0이 아니고, `energy` 값이 해당 `2^j` 번 점프할 수 있는 필요 에너지 이상인지 확인  
_0은 지면을 나타내고, 문제에서는 지면이 아닌 1번 방까지가 마지막이므로 0을 제외한 값일 때 이동_
- 한 번에 점프할 수 있으면 `energy` 값을 필요 에너지 만큼 줄이고, `pos` 값을 상위 부모 방으로 이동
- 위 과정들을 각 개미들마다 반복하여 1번 방에 가장 가까운 방인 `pos` 값을 출력
</details>

### 후기
- 로직 자체는 이해할 수 있으나, 자꾸 `dist[][]`, `parents[][]`에 각각의 할당해야 하는 공식을 넣는 것에 실수를 많이 함.