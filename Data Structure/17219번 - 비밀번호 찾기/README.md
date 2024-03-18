### 17219번: 비밀번호 찾기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/17219)

**문제 조건**
- 비밀번호가 랜덤으로 만들어져 경민이는 사이트의 주소와 비밀번호를 메모장에 저장
- 메모장에 등록한 사이트의 수가 많아지면서 단순히 눈으로 직접 찾는 것은 어려워짐
- 입력값으로 `n`개의 사이트주소와 찾고자 하는 `m`개의 사이트 주소를 입력 받음

**출력**  
- 입력받은 `m`개의 사이트에 알맞은 비밀번호를 각각 출력

### 풀이
1. 사이트의 주소를 `key`값으로 비밀번호를 `value`값으로 하는 `map`형을 선언
2. 사이트의 주소인 `domain`과 비밀번호 값인 `pass`를 선언
3. 각각의 입력값으로 `domain`을 `key`, `pass`를 `value`에 넣기
4. 찾고자 하는 사이트를 입력 받았을 때 `map`에서 `domain`인 `key`를 조회해서 출력

### 핵심 코드

```cpp
map<string, string> pw;

cin >> n >> m;

while(n--) {
    cin >> domain >> pass;
    pw.insert({domain, pass});
}
while(m--) {
    cin >> domain;
    cout << pw[domain] << "\n";
}
```