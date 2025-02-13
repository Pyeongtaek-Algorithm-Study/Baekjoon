### 5397번: 키로거

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/5397)
2. **도움 블로그** : https://8156217.tistory.com/54

**문제 조건**
- 비밀번호를 훔치기 위해 사용하는 컴퓨터에 키로거를 설치
- 키로거는 사용자가 키보드를 누른 명령을 모두 기록하며, 비밀번호를 입력할 때, **화살표나 백스페이스를 입력해도 정확한 비밀번호**를 알아낼 수 있음
- 비밀번호 창에서 입력한 키는 알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표임

**출력**  
- 각 테스트 케이스마다, **강산이의 비밀번호**를 출력

### 풀이
1. 삭제나 입력이 될때, 화살표로 인해 중간에 넣어야 하는 경우가 생기므로 _Vector_ 타입은 부적절
2. 따라서, _List_ 타입을 통해서 중간 입력 및 삭제를 이용
3. 화살표 _<,>_ 의 경우 각각 처음 위치 또는 마지막 위치가 아닐 경우에는 위치 변환이 가능
4. 백스페이스 _-_ 인 경우는 처음 위치만 아니면 해당 위치의 문자를 삭제할 수 있음
5. 문자일 경우에는 해당 커서 뒤에 문자를 넣고, 해당 커서의 위치를 1 증가시킴
6. 입력된 문자열을 각각 이어서 출력하면 해당 비밀번호를 출력할 수 있음

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    list<char> ans;
    list<char>::iterator cursor = ans.begin();
    
    for(char &c : logger) {
        if(c == '<') {
            if(cursor != ans.begin()) cursor--;
        }
        else if(c == '>') {
            if(cursor != ans.end()) cursor++;
        }
        else if(c == '-') {
            if(cursor != ans.begin()) cursor = ans.erase(--cursor);
        }
        else {
            cursor = ans.insert(cursor, c);
            cursor++;
        }
    }
    
    for(auto &it : ans) {
        cout << it;
    }
    cout << '\n';
}
```
- _List_ 타입의 `ans`와 해당 위치를 지정할 `cursor`을 선언
- 입력받은 비밀번호를 각각의 문자를 확인
- 화살표 방향일 때 각각 처음 위치 또는 마지막 위치인지 확인하여 `cursor`를 증가시킬 지, 감소 시킬 지를 설정
- 백스페이스인 경우, `cursor` 가 처음위치면은 삭제할 수 없고, 그 외의 경우 해당 `cursor` 위치의 문자를 삭제
- _List 타입은 Vector 타입과 다르게 삭제 한 후에, 해당 위치를 반환해서 받아줘야 함_
- 문자인 경우는 `cursor` 위치에 문자를 추가한 후, `cursor` 위치를 1 증가시킴
- 최종적으로 저장된 `ans`에 각각의 문자열을 출력함.
</details>

### 후기
- 중간 삽입을 해야하는 경우가 있으므로 _List_ 개념이 필요
- `erase()`로 _Vector_ 와 다르게 삭제 후 가리키는 곳이 필요하므로 `iterator`의 반환값이 필요  
https://blossoming-man.tistory.com/entry/cstdlisterase-%ED%95%A8%EC%88%98-%EC%82%AC%EC%9A%A9-%EC%8B%9C-%EB%B0%98%ED%99%98-%EA%B0%92%EC%9D%84-%EC%82%AC%EC%9A%A9%ED%95%98%EC%9E%90