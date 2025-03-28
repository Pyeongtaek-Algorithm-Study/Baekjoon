### 11003번: 최소값 찾기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/11003)
2. **도움 블로그** : 
    - https://velog.io/@deilee0913/BOJ-11003Ccpp
    - https://khjtoy.tistory.com/38

**문제 조건**
- N개의 수 $A_1, A_2, ..., A_N$과 L이 있음
- $D_i = A_{i-L+1} ~ A_i$ 중의 최솟값이라고 할 때, D에 저장된 수를 출력
- 이때, $i <= 0$ 인 경우 $A_1$로 대체하여 D를 구함

**출력**  
- $D_i$를 공백으로 구분하여 순서대로 출력

### 풀이
1. $D_i$는 현재 i 위치에서 이전 L 위치까지의 각 A값들 중 최솟값을 나타냄
2. 쉽게 슬라이딩 윈도우 내에서 최솟값을 출력하는 것이지만 단순하게 윈도우 내에서 최솟값을 구하는 식으로 하면 **시간초과** 발생
3. _Deque_ 타입을 통해서 앞의 원소, 뒤의 원소를 뺄 수 있도록 함
4. `dq`에 입력을 할 때, **해당 위치의 값과 몇번째** 위치인지 함께 넣음
5. `dq`에 저장된 첫번째의 위치값이 `i - l` 값보다 작으면은 윈도우 내의 값이 아닌 경우이므로 해당 원소를 제거
6. 입력할 값인 `num[i]`이 `dq`의 뒷 원소들의 값을 비교하여 더 작다면 **앞으로의 윈도우 내에선 `num[i]` 값이 최솟값**이므로 기존에 있던 dq 원소들이 필요없으므로 제거
7. 5번과 6번 과정을 통해 `dq`에는 윈도우 크기만큼 있으며 **첫번째 값에는 항상 해당 윈도우의 최솟값**이 들어가있음

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve_dq() {
    deque<pair<int, int> > dq;
    
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front().second <= (i - l)) dq.pop_front();
        while(!dq.empty() && dq.back().first > num[i]) dq.pop_back();
        
        dq.push_back({num[i], i});
        
        cout << dq.front().first << ' ';
    }
}
```
- _Deque_ 타입의 해당 위치의 값과 위치를 저장할 `dq`를 선언
- 순차적으로 확인하며 `dq`가 비어있지 않으며, `dq`의 첫번째의 위치 값이 해당 윈도우의 시작값보다 작은 경우 제거함
- `dq`가 비어있지 않으며, `dq`의 뒷부분을 계속 확인하여 현재 들어갈 원소값 `num[i]`가  더 작은 경우 앞으로의 **윈도우에는 들어갈 원소가 최솟값이 되고 기존에 있던 값들은 필요 없어지므로** 원소들을 제거
- 위 과정을 다 거친 후에, 현재 위치의 원소 값과 현재 위치를 입력함.
- `dq`의 첫번째 위치에서의 원소 값을 출력함
</details>

### 후기
- 윈도우 크기인 `L`과 원소 개수인 `N`이 최악의 경우 매우 오랜 시간이 소모되므로, 해당 칸을 들어갈 때마다 **최솟값을 찾는 로직을 구현**해야 했음
- _Deque_ 를 활용하여 단계별로 확인하는데 들어갈 원소가 최솟값인 경우에는 이전에 들어간 원소값들이 필요없어지므로 제거하는 것이 핵심이였음