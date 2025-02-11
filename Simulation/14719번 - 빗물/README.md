### 14719번: 빗물

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/14719)
2. **도움 블로그** : 

**문제 조건**
- 2차원 세계에 블록이 쌓여있으며 비가 오면은 블록 사이에 빗물이 고임
- 빗물은 블록이 현재 블록 높이보다 양 옆에 블록의 높이가 높을 때 고임
- 블록은 쌓여가기 때문에, 빈 공간이 생길 수 없고, 바닥은 항상 막혀있다고 가정
- 빗물 한 칸의 용량은 1

**출력**  
- 2차원 세계의 블록의 상태가 주어졌을 때, 고이는 빗물의 총량을 출력
- 빗물이 전혀 고여 있지 않을 경우 0을 출력

### 풀이
1. 가로를 기준으로, 첫번째 칸 부터 마지막 W길이 까지 각 칸에 빗물이 어느 높이까지 고이는지 확인
2. 현재 칸을 기준으로 왼쪽과 오른쪽을 구분지어서 **각각 최고 블록의 최고 높이**를 파악
3. 만일, 왼쪽과 오른쪽 중에 **높이가 0이라면은** 빗물이 쌓일 수 없으므로 제외
4. 왼쪽과 오른쪽의 블록의 높이 중에서 **더 작은 값**이 해당 칸에 빗물이 고일 수 있는 최고 용량
5. 해당 칸에 최고 용량과 현재 칸의 블록 높이를 비교하여 빗물의 용량이 더 높으면 _용량 - 블록의 높이_ 를 계산
6. 계산된 값을 최종적으로 구해야 할 총량에 더해줌

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    int ans = 0;
    
    for(int i = 0; i < w; i++) {
        int left = 0, right = 0;
        
        for(int j = 0; j < i; j++) left = max(left, block[j]);
        for(int j = i + 1; j < w; j++) right = max(right, block[j]);
        if(left == 0 || right == 0) continue;
        
        int rain = min(left, right);
        if(rain > block[i]) ans += rain - block[i];
    }
    
    cout << ans << '\n';
}
```
- 반복문을 통해 첫번째 칸부터 `w`칸까지 해당 칸에 쌓일 수 있는 빗물 용량을 측정
- 해당 칸을 기준으로 `left`과 `right`을 구분지어서 각각의 최고의 블록 높이 계산
- 왼쪽과 오른쪽 중에서 더 작은 값까지만 해당 칸의 빗물의 용량인 `rain`에 저장, 만일 높이가 0이 있을 경우 빗물이 고일 수 없으므로 건너감
- `rain`이 현재 칸의 블록 높이보다 높으면 최종 빗물 총 용량에 더함
</details>

### 후기
- 빗물이 고이는 것을 왼쪽과 오른쪽을 구분지어서 확인한다는 아이디어 구상이 어려웠음
- `left`와 `right`가 0이면은 빗물이 고일 수 없다는 것도 생각을 해야 했었음