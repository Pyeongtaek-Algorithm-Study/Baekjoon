### 9470번: Strahler 순서

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/9470)
2. **도움 블로그** : https://www.onlinegdb.com/online_c++_compiler

**문제 조건**
- 지질학에서 하천계는 유향그래프로 나타냄. 강은 간선으로 나타내며 물의 흐르는 방향이 간선의 방향
- 노드는 호수나 샘처럼 강이 시작하는 곳, 강이 합쳐지거나 나뉘는 곳, 바다와 만나는 곳
- 하천계의 _Strahler_ 순서
    - 강의 근원인 노드의 순서는 1
    - 나머지 노드는 그 노드로 들어오는 강의 순서 중 가장 큰 값을 i라고 할 때, 들어오는 모든 강 중에서 Strahler 순서가 i인 강이 1개이면 i, 2개 이상이면 순서는 i + 1
- 쉽게 설명하면, **강의 시작은 1**이고, 나머지 강의 순서 값은 들어오는 강의 값의 큰 값을 i인데 **1개이면 i 값 그대로이고, 2개 이상이면 i + 1**이라는 것


**출력**  
- 각 테스트 케이스마다 테스트 케이스의 번호와 **하천계의 Strahler의 값**을 출력

### 풀이
1. 하천계의 _Strahler_ 의 값은 결국 최종 마지막 강 하류의 값과 마찬가지(최댓값이 저장됨)
2. 마지막 하류까지 도달할 때까지 결국 강의 순서가 존재하는 것이므로 _위상 정렬 알고리즘_ 사용
3. 각 강의 _Strahler_ 의 값을 저장할 수 있는 값과 해당 들어오는 가장 큰 값이 2개 이상인지 체크할 **배열**이 필요
4. 강의 근원 들을 _Queue_ 에 추가한 후, 각각의 다음 순서들의 _Degree_ 값을 감소
5. 다음 강의 _Strahler_ 값이 현재 강의 값과 비교하여 최댓값이 2개 이상이 되면 +1 한 값으로 하고, 들어가는 값이 더 큰 값이면 값을 갱신
6. 위 과정을 반복하여 강의 최종 하류까지 도달할 때까지 반복하며 현재 테스트 케이스와 _Strahler_ 의 최댓값을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    queue<int> Q;
    int ans = 0;
    
    for(int i = 1; i <= m; i++) {
        if(!degree[i]) {
            Q.push(i);
            strahler[0][i] = 1;
        }
    }
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        ans = max(ans, strahler[0][cur]);
        
        for(int i = 0; i < river[cur].size(); i++) {
            int ncur = river[cur][i];
            if(strahler[0][ncur] < strahler[0][cur]) {
                strahler[0][ncur] = strahler[0][cur];
                strahler[1][ncur] = 0;
            }
            else if(strahler[0][ncur] == strahler[0][cur] && !strahler[1][ncur]) {
                strahler[0][ncur]++;
                strahler[1][ncur] = 1;    
            }
            
            if(--degree[ncur] == 0) Q.push(ncur);
        }
    }
    
    cout << k << ' ' << ans << '\n';
}
```
- 기본적인 위상 정렬 알고리즘( _구체적인 설명은 건너뜀_ )
- `ans` 값에는 하류 _Strahler_ 의 최댓값을 갱신
- 강의 다음 순서인 `ncur` 과 현재 강인 `cur`의 `strahler[][]`을 통해서 최댓값을 비교
- 만일 들어가는 강의 순서 값이 더 큰 경우 값을 갱신하고 `strahler[1][]` 값에는 0을 대입
- 현재 들어가는 강의 순서 값이 같은 경우 들어가는 값이 2개 이상이므로 `strahler[0][ncur]++` 진행하여 값을 증가
- 더 이상 증가하지 않도록 strahler[1][] 값을 1로 설정하여 차단
- 위 과정을 모든 강의 하류까지 도달할 때 까지 반복
- 최종적인 해당 테스트 케이스인 `k`와 `ans` 값을 출력
</details>

### 후기
- 위상 정렬까지는 구현했으나, 강의 Strahler 값이 2개 이상이 들어오는 것을 비교하는 if문을 따로 추가하지 않아 틀렸음..