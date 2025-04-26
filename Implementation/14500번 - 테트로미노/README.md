### 14500번: 테트로미노

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14500)
2. **도움 블로그** : 
		- https://0m1n.tistory.com/32
		- https://jangkunstory.tistory.com/119

**문제 조건**
- 폴리오미노란 크기가 1 X 1인 정사각형을 여러 개 이어서 붙인 도형
- 정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며 5가지 모양이 존재
![테트로미노](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14500/1.png)
- 아름이는 크기가 N X M인 종이 위에 **테트로미노 하나**를 놓고, 각각의 칸에 정수가 쓰여 있음
- 테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, **회전이나 대칭**을 시켜도 됨.

**출력**  
- 테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 **수들의 합의 최댓값**을 출력

### 풀이
1. 테트로미노의 5개의 모양에서 T자 모양을 제외하면은 한 점에서 시작해서 임의의 상하좌우로 4칸씩 이동하면 모양이 완성됨.
2. 이를 활용해서 한 점에서 _DFS_ 를 통해 **상하좌우로 3칸씩 갈 수 있는 모든 경우**를 살펴보면은 T자를 제외한 나머지 4개의 테트로미노의 회전, 대칭 모양을 구현한 것과 같음
3. 위 방법으로 4칸일 때의 수의 합산을 구해서 최댓값일 경우 값을 갱신
4. **T자 모양**은 _DFS_ 만으로 구현할 수 없으므로 따로 구현해서, 값의 합산을 구해 최댓값과 비교
5. N X M의 각각의 칸에 다 진행하여 최종적으로 구한 **최댓값을 출력**

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void back(int x, int y, int cnt, int sum) {
    if(cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    
    if(!vis[x][y]) {
        vis[x][y] = true;
        sum += paper[x][y];
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny]) {
                back(nx, ny, cnt + 1, sum);
            }
        }
        vis[x][y] = false;
    }
}
```
- _DFS_ 함수로 현재 칸인 `x`, `y`와, 이동했던 칸의 개수 `cnt`, 이동한만큼의 숫자의 합인 `sum`
- cnt가 4개 일 경우 테트로미노 모양이므로 이 때의 `sum`과 최종 결과값인 `ans`와 비교하여 최댓값으로 갱신
- 지나온 칸을 `vis[][]`을 통해 방문처리 후, 다시 되돌아왔을 때 해제
- 이 함수를 통해서 **T자를 제외한 4개의 테트로미노**의 회전과 대칭의 모든 모양일 때의 보드 숫자의 합산을 알 수 있음

```cpp
void t(int x, int y) {
    for(int dir = 0; dir < 4; dir++) {
        int t_sum = paper[x][y];
        
        for(int i = 0; i < 4; i++) {
            // 상하좌우중 1개씩을 건너뜀
            if(i == dir) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m) t_sum += paper[nx][ny];
        }
        ans = max(ans, t_sum);
    }
}
```
- `t`함수는 현재 칸을 기준으로 상하좌우 4칸을 조사함
- **T자 모양의 회전**은 현재 칸 기준 상하좌우로 1칸씩이 없는 모양
- 현재 칸의 수를 `t_sum`에 대입
- 상하좌우로 4번씩 1칸씩만 없는 경우를 구해서 해당 수들을 `t_sum`에 합산
- 최댓값을 저장할 `ans`와 `t_sum`을 비교해서 갱신

</details>

### 후기
- T모양을 제외한 나머지 모양들이 _DFS_ 를 통해 탐색하는 모양이라는 것을 유추하는 것이 어려웠음