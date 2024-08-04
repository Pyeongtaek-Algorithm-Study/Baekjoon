### 2661번: 좋은수열

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/2661)
도움 블로그 : https://blogshine.tistory.com/216

**문제 조건**
- 숫자 1,2,3으로만 이루지는 수열
- **임의의 길이의 인접한 두 개의 부분에서 수열이 동일한 것**이 나타나면, 해당 수열을 "나쁜 수열"  
_ex. [33], 3[2121]323, [123123]213_
- 따라서, 수열애서 1,2,3으로 만 이뤄줬으며, 나쁜 수열이 아닌 것을 **"좋은 수열"**들

**출력**  
- 길이가 `N` $(1<=N<=80)$ 인 수열 중에서 가장 작은 수인 수열을 출력

### 풀이
1. `n`을 입력받아 문자열의 길이가 `n`일 떄까지 `backtraking()`을 실행
2. 문자열 `res`에 가능한 문자인 1, 2, 3을 뒤에 붙인다.
3. 문자열에 문자를 붙일 때마다, `isbad()` 를 통해서 문자열이 나쁜 수열인지 파악
4. 문자열의 맨 뒤를 기준으로 `front`와 `back`으로 길이가 1, 2, .., len / 2 문자를 비교
5. 문자열 `s`에서 추출된 `front`와 `back`이 같다면 반복되는 수열이 있는 것이므로 나쁜 수열
6. 문자열 `s`의 절반 길이인 len / 2까지 반복하여 같은 문자열이 없으면, 좋은 수열
7. 좋은 수열로 파악될 시, 문자열이 길이 `n`과 같을 때 출력하고 `backtracking()` 종료

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void backtrackging(string s, int len) {
    if(isbad(s)) return;
    if(len == n) {
        res = s;
        cout << res << "\n";
        exit(0);
    }
    backtrackging(s + "1", len + 1);
    backtrackging(s + "2", len + 1);
    backtrackging(s + "3", len + 1);
}

bool isbad(string s) {
    int len = s.length();
    int half = len / 2;
    
    for(int i = 1; i <= half; i++) {
        string front = s.substr(len - (i * 2), i); 
        string back = s.substr(len - i, i); 
        if(front == back) return true;
    }
    return false;
}
```
**backtracking**
- 함수에 입력받은 문자열 `s`에 대하여 `isbad()`를 통해 나쁜 수열인지 좋은 수열인지 파악 
- 좋은 수열의 문자열에서 길이가 `n`과 같으면 조건을 만족하면서 가장 작은 수인 문자열이므로 함수 종료
- 문자열의 길이가 부족하므로 1, 2, 3 문자를 뒤에 붙여보며, 반복

**isbad**
- `len`은 문자열의 전체 길이, `half`는 문자열의 전체 길이의 반
- 1부터 `half`까지 반복하여 `front`와 `back` 문자열을 통해 문자열 `s`에서 맨 뒤를 기준으로 길이만큼 잘라서 비교
- `front`와 `back`의 문자열이 같으면은 서로 반복되는 수열이므로 나쁜 수열로 파악

</details>

### 후기
- 처음 문제를 접할 떄는 난이도를 요구하는 듯했으나, 풀이법을 보면은 생각외로 간단
- 문제의 핵심은 해당 수열이 나쁜 수열인지 판단하는 기준
- 백트래킹할 때 1, 2, 3순으로 하므로 작은 수부터 시작하니깐 가장 처음으로 만족하는 수열이 문제의 정답