### 6198번: 옥상 정원 꾸미기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/6198)
2. **도움 블로그** : 

**문제 조건**
- 도시에 N개의 빌딩이 있으며, 빌딩 관리자들은 다른 빌딩의 옥상 정원을 벤치마킹하고자 함
- i번째 빌딩의 키가 $h_i$ 이며 볼 수 있는 정원은 i+1, i+2, ..., N이고, 모든 빌딩은 일렬로 서 있고 **오른쪽**으로만 볼 수 있음
- 빌딩 관리자는 자신의 빌딩보다 높은 빌딩은 볼 수 없으며 그 다음에 있는 모든 빌딩의 옥상을 보지 못함

**출력**  
- 각 빌딩관리자가 **벤치마킹이 가능한 빌딩의 수**들의 총합을 출력

### 풀이
1. 빌딩이 벤치마킹하기 위해서 자신의 빌딩보다 높이들이 낮아야 함.
2. 즉, 현재 빌딩이 이전 빌딩의 높이보다 크면은 **이전 빌딩들은 벤치마킹을 할 수 없으므로 제외**해도 됨
3. 위 아이디어로 높이가 크면은 _Stack_ 으로 이전 빌딩들을 빼버림
4. 해당 빌딩에서 _Stack_ 에 앞선 빌딩들이 있으면은 **앞선 빌딩은 해당 빌딩을 벤치마킹이 가능**하므로 해당 크기만큼을 `ans`에 더함
5. 이후에, 해당 빌딩을 _Stack_ 에 넣고 마지막 빌딩까지 위 과정을 반복
6. 최종적으로 `ans`에는 각 빌딩들이 벤치마킹이 가능한 수들의 총합이 저장되므로 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    stack<int> roof;
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        while(!roof.empty() && roof.top() <= v[i]) {
            roof.pop();
        }
        ans += roof.size();
        roof.push(v[i]);
    }
    
    cout << ans << '\n';
}
```
- 관리자가 볼 수 있는 옥상을 나열할 `roof`
- 각 빌딩을 순회하면서 해당 빌딩의 높이가 `roof`의 최상단 값과 크거나 작으면은 이전 빌딩들은 높이로인해 해당 빌딩 넘어서 볼 수 없으므로 값을 제외
- `roof`에 빌딩들이 있으면은 해당 빌딩의 개수들을 총합에 더해줌
- 이후에, 해당 빌딩을 `roof`에 넣음
- 위 과정을 마지막 빌딩까지 반복한 후에 `ans` 값에는 각 빌딩이 벤치마킹이 가능한 개수들의 총합이므로 이를 출력
</details>

### 후기
- 이놈의 long long.. 결과값이 int형을 넘을 수 있다는 것이 항상 빼먹음
- 보통 5% 미만에서 걸리는 것은 **출력 타입을 의심**해봐야 겠음