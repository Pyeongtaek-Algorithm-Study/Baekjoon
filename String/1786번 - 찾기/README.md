### 1786번: 찾기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1786)
2. **도움 블로그** : 
    - https://i-never-stop-study.tistory.com/136
    - https://i-never-stop-study.tistory.com/135


**문제 조건**
- 문서 프로그램에서 찾기 기능이 있음(_Ctrl + F_)
- 두 개의 문자열 P와 T에 대해, 문자열 P가 문자열 T 중간에 몇 번, 어느 위치에서 나타내는지 알아내는 문제를 '문자열 매칭'
- P는 패턴, T는 텍스트
- 이하 문장들은 _KMP_ 알고리즘에 대한 설명

**출력**  
- 문자열 T에서 P가 몇 번 나타내는지 음이 아닌 정수로 출력 후, 각 패턴이 나타나는 위치를 공백으로 구분해 출력

### 풀이
1. KMP 문제으로, 문자열 찾는 시간 복잡도가 O(n)만큼인 알고리즘
2. `get_pi()` 를 통해서 패턴의 접두사, 접미사가 일치하는 길이를 파악
3. 파악한 길이를 통해서 입력받은 문자열에서 패턴과 비교해가면서 패턴과 일치하던 중 틀린 부분부터의 앞 부분의 건너뜀으로써 시간 복잡도를 낮춤
4. 결론적으로, 문자열에서 각 자리당 비교하면서 **틀린부분부터 다시 앞 패턴을 일치**시키면서 빠르게 찾아 해당 패턴의 시작 위치들을 _Vector_ 에 담음
5. _Vector_ 에 담긴 길이를 출력한 후에, 각각의 원소들을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
vector<int> get_pi(string p) {
    int len = p.length();
    vector<int> table(len, 0);
    
    int j = 0;
    for(int i = 1; i < len; i++) {
        while(j > 0 && p[i] != p[j]) j = table[j-1];
        if(p[i] == p[j]) table[i] = ++j;
    }
    
    return table;
}
- 입력받은 패턴의 문자열 `p`에서 각각의 위치에서 접두사의 반복 문자열이 몇 번째를 나타내는 것을 반환하는 함수

```cpp
vector<int> kmp(string s, string p) {
    vector<int> ans;
    vector<int> table = get_pi(p);
    int s_len = s.length();
    int p_len = p.length();
    int j = 0;
    
    for(int i = 0; i < s_len; i++) {
        while(j > 0 && s[i] != p[j]) j = table[j-1];
        if(s[i] == p[j]) {
            if(j == p_len - 1) {
                ans.push_back(i - p_len + 2);
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    
    return ans;
}
```
- _KMP_ 알고리즘 함수로, `table` 값에는 `p`의 문자열 내부에서 접두사가 반복되는(?) 그런 순서가 저장
- `s` 에서 각 자리별로 패턴의 위치와 확인하여 틀린 부분을 확인
- 틀린 부분이 확인 되면, `j` 위치에서 `table`의 위치를 파악하여 해당 위치에서부터 확인(?)
- 코드 자체를 완벽하게 _이해하진 못해_, 관련한 자료를 추가적으로 이해 해야 함..
</details>

### 후기
- `cin.ignore()` 를 해야 하는 줄 알았지만, `getline()`을 연속으로 사용하면 필요 없다는 것을 깨달음. (https://starrykss.tistory.com/1971)
- 갠적으로, 아직 정확하게 이해가 잘 되진 않는 알고리즘으로.., 패턴을 익혀야 겠음.