### 1062번: 가르침

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1062)

**문제 조건**
- 선생님은 N개의 단어와 임의의 K개의 알파벳(글자)를 사용
- 남극언어의 모든 시작은 "anta"로 시작되고, "tica"로 끝  
_'a','c','i','n','t'의 알파벳이 필수적으로 필요_

**출력**  
- 임의의 K개의 알파벳를 사용해 읽을 수 있는 단어 개수의 최댓값 출력

### 풀이
1. 기본적으로 5개의 알파벳이 최소한으로 필요('a','c','i','n','t')
2. `K`개 5개 미만이면 읽을 수 있는 단어가 없으므로 0을 출력
3. `K`개 5개 이상일 경우 나머지 선택할 수 있는 알파벳은 $K - 5$ 개
4. 알파벳은 최대 26개이므로 이는 `Bitmask`로 int형으로 치환 가능
5. 입력 받은 `N`개의 단어들을 정수형으로 치환
6. `K-5`개의 알파벳을 선택하고 선택이 완료되면 `AND 연산`으로 단어 값이 그대로 나올 경우 읽을 수 있는 단어이므로 `cnt++`
7. 단어 개수만큼 반복하여 `max()`를 통해 최댓값을 비교
8. 백트래킹을 통해 다른 알파벳을 골라가며 최종 최댓값 찾기 

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void input() {
    cin >> n >> k;

    alpha |= (1 << ('a' - 'a'));
    alpha |= (1 << ('c' - 'a'));
    alpha |= (1 << ('i' - 'a'));
    alpha |= (1 << ('n' - 'a'));
    alpha |= (1 << ('t' - 'a'));
    vector<int> tmp(n, 0);

    for(int i = 0; i < n; i++) {
        string s = "";
        cin >> s;
        for(int j = 0; j < s.length(); j++) 
            tmp[i] |= (1 << (s[j] - 'a'));
    }
    
    v = tmp;
}
```
- `Bitmask`의 연산으로  `|=` 는 알파벳을 int형으로 치환
- 입력받은 `N`개의 단어들도 `Bitmask`를 통해 각 `int`형으로 치환
```cpp
void dfs(int alpha, int level, int idx) {
    if(!level) {
        int cnt = 0;

        for(int i = 0; i < n; i++)
            if((alpha & v[i]) == v[i]) cnt++;

        result = max(result, cnt);
    }
    else {
        int x = 0;

        for(int i = idx; i < 26; i++) {
            x = 1 << i;
            if((alpha & (x))) continue;
            alpha |= x;
            dfs(alpha, level - 1, i);
            alpha ^= x;
        }
    }
}
```
- `level`은 선택할 수 있는 남은 알파벳 개수로 0일 경우 **알파벳을 모두 선택완료 한 것이므로** 읽을 수 있는 단어를 체크
- `level`이 남아있을 경우 `alpha`에 `i`번째의 알파벳을 추가하고 `dfs()`로 재귀
- `max()`를 통해 읽을 수 있는 단어 최댓값 비교후 `^=` 연산을 통해 백트래킹으로 알파벳을 순환하며 선택
</details>