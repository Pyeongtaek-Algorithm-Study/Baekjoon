### 9935번: 문자열 폭팔

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/9935)
2. **도움 블로그** : 

**문제 조건**
- 문자열에 폭팔 문자열이 존재. 폭팔 문자열이 폭팔하면 그 문자열애서 사라지며, 남은 문자열끼리은 다시 합쳐짐
- 포팔은 다음과 같은 과정으로 진행
    1. 문자열에 폭발 문자열을 포함하고 있는 경우에, 모든 폭팔 문자열이 폭팔. 남은 문자열은 순서대로 이어 붙여 새로운 문자열 생성
    2. 새로 생긴 문자열에 폭발 문자열이 포함되고 있을 경우 폭팔
    3. 새로운 문자열에 폭발 문자열이 없을 때 까지 반복

**출력**  
- 모든 폭팔이 끝난 후에 어떤 문자열이 남아 있는지 출력. 만약 남아 있는 문자열이 없을 경우 "FRULA"를 출력

### 풀이
1. 문제 풀이 설명

### 핵심 코드

<details>
<summary>코드 보기</summary>

```CPP
int bomb_len = bomb.length();
string result = "";
stack<char> S;

for(int i = str.length() - 1; i >= 0; i--) {
    S.push(str[i]);
    if(S.top() == bomb[0]) {
        string tmp = "";
        tmp += S.top(); S.pop();
        bool chk = false;
        for(int j = 1; j < bomb_len && !S.empty(); j++) {
            if(S.top() != bomb[j]) {
                chk = true;
                break;
            }
            tmp += S.top(); S.pop();
        }
        if(chk || tmp.length() != bomb_len) {
            for(int j = tmp.length() - 1; j >= 0 ; j--) {
                S.push(tmp[j]);
            }
        }
    }
}
while(!S.empty()) {
    result += S.top(); S.pop();
}
```
- 코드 설명
</details>

### 후기
- 문자열을 합치는 부분에서 substr를 사용하면은 시간초과가 발생. 해당 함수 내부에 반복문이 있는 듯 해보임.
- 먼가 양은 많으면은 그저 순서대로 흘러가면서 조건을 살펴봐야하는 경우는 stack을 활용해야 하는 듯하다.