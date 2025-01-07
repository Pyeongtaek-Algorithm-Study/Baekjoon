### 12015번: 가장 긴 증가하는 부분 수열 2

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/12015)
2. **도움 블로그** : https://hyeo-noo.tistory.com/32

**문제 조건**
- 수열이 주어졌을 떄, 수열의 일부 원소들을 통해 부분 수열 생성
- 만든 부분 수열은 원소의 첫번쨰부터 마지막까지 증가하는 원소들로 구성이 됨

**출력**  
- 수열에서 만들 수 있는 **증가하는 부분 수열의 최대 길이**를 출력

### 풀이
1. 증가하는 부분 수열의 길이를 보통 _DP_ 로 풀지만 수열이 매우 길기에 이중 반복문 불가
2. 부분 수열을 구성할 `aes_num`을 선언
3. 원소들을 순차적으로 확인하여 `aes_num`의 마지막 원소와 비교하여 들어갈 원소가 더 크다면 추가
4. 만일 들어갈 원소가 마지막 원소보다 작다면은 들어갈 원소보다 큰 값 이전의 위치를 바꿈
5. 위 과정에서 위치를 찾을 떄 _Binary Search_ 알고리즘을 통해 시간을 줄임
6. 위 과정을 들어갈 원소들을 전부 다 확인하면은 `aes_num` 수열에는 원소들 간의 격차가 줄어들면서 내부적으로 증가되는 수열 구성됨.  
_가장 길게 증가하는 부분 수열을 만들려면 증가하면서 **앞 뒤 원소의 차이가 매우 작을수록 유리**, 원소를 바꾸는 것 자체는 길이에 추가적인 영향이 아님_

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
int lowerBound(vector<int> &num, int k) {
    int l = 0;
    int r = num.size() - 1;
    int half = r;
    
    while(l < r) {
        half = (l + r) / 2;
        
        if(k > num[half])
            l = half + 1;
        else
            r = half;
    }
    
    return r;
}
```
- 부분 수열과 넣을 원소 값을 매개변수로 입력받아, 넣을 원소 값이 부분 수열에 어느 위치에 넣어야 하는지를 결정하는 함수
- 넣을 위치는 해당 원소 값보다 큰 값 이전의 위치에 바꿀 것이며, 탐색 과정을 _Binary Search_ 방법으로 구성
- 일반적인 코드 구성이라 추가적인 설명은 안함

```cpp
void solve() {
    int ans = 1;
    aes_num.push_back(v[0]);
    
    for(int i = 1; i < n; i++) {
        if(v[i] > aes_num.back()) {
            aes_num.push_back(v[i]);
            continue;
        }
        int idx = lowerBound(aes_num, v[i]);
        // int idx = lower_bound(aes_num.begin(), aes_num.end(), v[i]) - aes_num.begin(); // 내장함수
        aes_num[idx] = v[i];
    }
    
    cout << aes_num.size() << '\n';
}
```
- `aes_num` 배열에 첫번째 원소값을 저장
- 이후 추가할 원소부터 마지막까지 원소값을 비교하여 `aes_num`에 추가하거나 값을 바꿀것인지 결정
- `aes_num`의 마지막 원소 값보다 넣을 원소 값이 더 크면은 값을 추가
- `aes_num`의 마지막 원소 값보다 넣을 원소 값이 더 작으면은 `lowerBound()`를 이용하여 바꿀 위치 값을 반환 받음
- 본 코드에서는 직접 코드로 작성했지만, `lower_bound(시작, 종료, 찾고자하는 값)-시작` 을 하는 값과 동일
- 반환 받은 위치에 넣을 원소 값을 저장
- 이후 모든 원소들을 다 확인 한 후에 `aes_num`의 길이를 출력

</details>

### 후기
- c++에서 타입을 할때 복사할 때는 &를 붙이는 것이 시간초과를 방지할 수 있음