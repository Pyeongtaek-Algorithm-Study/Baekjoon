### 2668번: 숫자고르기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/2668)
2. **도움 블로그** : 

**문제 조건**
- 세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있으며 첫째 줄은 1, 2, ..., N이 차례대로 있으며 둘째 줄은 각 칸에 1이상 N이하의 정수
- 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과 둘째 줄에 들어있는 정수들이 이루는 집합이 일치

![예시 사진](https://www.acmicpc.net/upload/images/u5JZnfExdtFXjmR.png)
- 위와 같은 사진일 때, 첫째 줄에 1, 3, 5번을 선택하면 둘째 줄의 3, 1, 5로 숫자들이 이루는 집합이 일치


**출력**  
- 첫째 줄에 뽑힌 정수들의 **최대 개수**를 출력하고 그 다음 줄부터 **뽑힌 정수들을 오름차순**으로 한 줄씩 출력

### 풀이
1. 첫째 줄 값과 둘째 줄의 집합이 서로 같으려먼, 탐색하다가 순환을 이뤄야 함.
2. 따라서 방문을 체크하는 것과 순환을 할 수 있는 재귀함수를 구현
3. 임의의 값이 재귀로 탐색하면서 이미 방문을 했던 곳을 찾을 때까지 반복
4. 이후에, **처음 시작한 값과 마지막에 도달한 값이 같으면**은 처음 시작한 값은 집합에 넣어도 되는 것
5. 이를 1 ~ N번째까지 반복하며, 할 때마다 방문 체크는 초기화
6. 최종적으로 추가된 집합에 크기를 출력하고 순차적으로 집합의 요소를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void recursive(int st, int val) {
    if(arr[0][val]) {
        if(st == val) res.push_back(st);
        return;
    }
    arr[0][val] = 1;
    recursive(st, arr[1][val]);
}

void solve() {
    for(int i = 1; i <= n; i++) {
        fill_n(&arr[0][0], 101, 0);
        arr[0][i] = 1;
        recursive(i, arr[1][i]);
    }
    cout << res.size() << '\n';
    for(int &it : res) cout << it << '\n';
}
```
- `arr`에서 첫번째 줄은 순환할 때의 방문을 체크하는 용도
- 1부터 `N`까지 반복할 때 해당 `i`번째를 먼저 1로 체크를 해놓고 순환을 시작
- `recursive()`에서 `st`는 해당 시작 값을 의미하고, `val`은 위치의 두번째 줄의 값을 의미
- `val`에 다음 위치 값을 `arr`의 첫번째에 방문 표시를 해놓고, 다시 재귀로 돌려서 해당 `val` 값의 다음 값을 순환
- 재귀적으로 탐색하다가 `arr[0][]` 를 체크할 때, 이미 방문했던 거라면은 여태 탐색하면서 순환적으로 돌아온 것
- `val`과 `st`값을 비교하여 같다면은 쭉 순환돌다가 다시 원점으로 돌아온 것이므로 `res`에 해당 `st`값을 추가
- 이런 식으로 1 ~ N까지 반복
- 최종적으로 `res`의 값의 개수를 출력한 후, `res`는 오름차순으로 순차적으로 입력됬으므로 출력
</details>

### 후기
- 순환이 중요하며, 이를 무한루프에 빠지지 않도록 방문을 표시해야 했음
- 아이디어 구상이 어려웠음