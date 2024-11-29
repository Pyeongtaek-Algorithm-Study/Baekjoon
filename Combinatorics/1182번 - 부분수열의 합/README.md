### 1182번: 부분수열의 합

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1182)
2. **도움 블로그** : 

**문제 조건**
- N개의 정수로 이루어진 수열
- 이 수열에서 크기가 양수인 부분수열을 가질 수 있음

**출력**  
- 부분수열 중 각 원소의 합이 S가 되는 경우의 수를 출력

### 풀이
1. 백트래킹으로도 가능하지만, 이 설명에서는 **조합론**을 통해 설명
2. 크기가 양수이므로, 부분수열의 크기는 1 ~ N개 까지 가능
3. 각 크기마다 조합 알고리즘을 통해 부분수열을 생성
4. 부분수열의 각 원소를 `total`에 합산
5. `total` 값과 입력받은 `s`값과 비교하여 같으면은 최종 값 개수를 증가

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> chk(i, 1);
        for(int j = 0; j < n - i; j++) chk.push_back(0);
        sort(chk.begin(), chk.end(), compare);
        
        do {
            int total = 0;
            for(int k = 0; k < n; k++) if(chk[k]) total += seq[k];
            if(s == total) ans++;
        } while(next_permutation(chk.begin(), chk.end()));
    }
    
    cout << ans << '\n';
}
```
- `ans`는 출력해야 할 최종 부분수열의 개수, `chk`는 부분수열을 결정할 정수 위치를 나타내는 것
- 1 ~ `n`개 까지를 한 후에 부분수열에서 활성화할 개수를 설정한 후 `next_permutation()`으로 순열 생성
- `chk[]`에 부분수열을 만들 위치가 정해지면 해당 위치의 정수들을 `total`에 합산
- `total`과 `s`가 같으면은 해당 부분수열의 원소들이 `s`를 이루는 것으로 `ans`를 증가
</details>

### 후기
- 