### 10816번: 숫자 카드 2

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/10816)
2. **도움 블로그** : https://breakcoding.tistory.com/188

**문제 조건**
- 숫자 카드는 정수 하나가 적혀져 있는 카드
- 상근이는 숫자 카드 N개를 가지고 있음

**출력**  
- 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 **상근이가 몇 개 가지고 있는지**를 공백으로 구분해 출력

### 풀이
1. 본 풀이는 C++ 의 이분 탐색을 기준으로 설명
2. C++의 _Algorithm_ 헤더 안에는 `lower_bound()`, `upper_bound()`가 존재
3. 각각 찾고자 하는 값의 위치를 이분 탐색 진행
    - `lower`는 정렬된 리스트에서 내가 찾고자 하는 값의 시작하는 위치
    - `upper`는 정렬된 리스트에서 내가 찾고자 하는 값의 마지막 위치보다 1 큰 위치
4. 따라서 `upper`에서 `lower`의 위치 값을 빼면은 원하는 값의 개수를 알 수 있음

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    sort(cards.begin(), cards.end());
    
    for(int amount : amounts) {
        int st_idx = lower_bound(cards.begin(), cards.end(), amount) - cards.begin();
        int end_idx = upper_bound(cards.begin(), cards.end(), amount) - cards.begin();
        cout << end_idx - st_idx << ' ';
    }
}
```
- 입력받은 `cards`를 오름차순으로 정렬
- 찾고자 하는 카드인 `amount`를 값으로 `lower_bound()`, `upper_bound()`를 통해 위치를 찾음
- 정확한 위치를 저장하기 위해선 뒤에 리스트의 시작 위치를 빼야 함.
- 찾고자 하는 위치를 `st_idx`, `end_idx`에 저장한 후 각 차이를 출력
</details>

### 후기
- c++의 헤더파일에 `binary_search()`로 별도로 존재하며 true, false가 있다는 것도 따로 알게됨.