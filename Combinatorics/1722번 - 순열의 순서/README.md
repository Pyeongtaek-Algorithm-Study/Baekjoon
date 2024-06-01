### 1722번: 순열의 순서

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1722)

**문제 조건**
- 1부터 N의 까지의 값이 저장된 배열에서 순열 찾기
- 첫째 줄에 N(1≤N≤20) 을 입력받고, 두번째 줄 처음 값이 1이면은 입력받은 배열 순서중 k(1≤k≤N!)번째의 순열을 출력하고 2이면은 임의의 순열을 입력받아 몇 번째 순열인지 출력

**출력**  
- 1을 입력받은면은 **k번째 수열** 출력 또는 2일 경우 **해당 수열이 몇번 째 수열**인지 출력

### 풀이
1. 순열을 찾기 위해 보통 C++에서는 `next_permutation()`를 사용하지만, 최악의 경우 20!만큼 계산해야 하므로 `BruteForce` 방식으론 **시간초과** 발생
>  **순열 문제 풀이**  
    -  {3 4 1 2}의 순열의 순서를 찾는 방법은 맨 앞 자리 수 부터 순서 파악  
    - 3이므로 1,2(2개)의 각 순열를 모두 거친것 : 2 X 3!(뒤의 3자리 순열)  
    - 다음 수인 4로 1,2,3의 순열을 지나간 것인데 앞선 3의 숫자를 사용했으므로 3을 제외한 1,2(2개)의 순열을 지난 것 : 2 X 2!(뒤의 2자리 순열)  
    - 다음 수인 1로 가장 처음 순열 순서 : 1 X 1!(뒤의 1자리 순열)  
    - 다음 수인 2는 마지막 숫자로 자동 고정 : 0  
    - 나온 경우의 수들의 총합이 곧 해당 순열 번째 : $$2 \times 3! + 2 \times 2! + 1 \times 1! + 0 = 17$$
3. 두번째 줄에 입력 받은 값이 2인 경우 위의 방식대로 계산, 1인 경우 입력 받은 k의 값에 반대로 빼서 해당 번째 숫자 값 출력
4. `n`과 1, 2의 값을 저장할 `l`, 20!을 입력받을 수 있도록 `long long k` 선언과 순열을 저장하도록 `vector<int> v` 선언

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    int chk[n + 1] = {0, };
    long long factorial[n + 1];
    factorial[0] = factorial[1] = 1;
    for(int i = 2; i <= n; i++) factorial[i] = i * factorial[i - 1];
    
    if(l == 1) {
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= n; j++) {
                if(chk[j-1]) continue;
                if(k > factorial[i]) k -= factorial[i];
                else {
                    chk[j-1] = 1;
                    cout << j << " ";
                    break;
                }
            }
        }
    }
    else {
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < v[i - 1]; j++) {
                if(chk[j]) continue;
                ans += factorial[n - i];
            }
            chk[v[i - 1]] = 1;
        }
        cout << ans;
    }
}
```
- 순열의 값을 계산하기 위해 20번째까지 `factorial` 계산한 후, `chk[]`로 각 숫자들의 사용유무 확인
- `l`이 1인 경우, 맨 처음 숫자 번째의 `factorial`값을 빼면서 해당 숫자 출력 -> 해당 수는 `chk[]`에 체크
- `l`이 2인 경우, `ans`에 `v`의 처음 값부터 `n-i`번째 `fatorial` 값을 `ans`에 더하고, `chk[]` 배열에 해당 숫자 체크
- 입력 받은 배열의 순서를 다 돌며 `ans`에 값 추가

</details>