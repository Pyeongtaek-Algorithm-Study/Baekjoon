### 1874번: 스택 수열

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1874)
2. **도움 블로그** : 

**문제 조건**
- 스택은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념(LIFO)
- 1부터 n까지 수를 스택에 넣었다가 빼는 것을 늘어놓음으로써, 하나의 수열을 만듬
- 단, 스택에 수를 넣을 때 **오름차순**을 지킴
- 어떤한 수열을 만들 수 있는지 없는지 확인하고, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지 알아낼 수 있음

**출력**  
- 입력된 수열을 만들기 위해 필요한 연산인 push와 pop을 **각각 +, -로 각각의 줄**로 출력
- 만일 해당 수열을 **만들 수 없을 경우**, NO를 출력

### 풀이
1. _Stack_ 에 수를 수열의 해당 값일 때까지 **오름차순**으로 계속해서 넣는다.
2. _Stack_ 의 상단 값이 출력해야 할 값일 경우 Pop() 연산 진행
3. 만일, _Stack_ 의 상단 값이 수열의 해당 값보다 큰 경우 **해당 값이 Stack 중간에 속해있어 올바른 수열을 만들 수 없으므로** NO를 출력
4. 위 과정이 정상적으로 끝나면 _Stack_ 에 push했을 때, pop했을 때의 각각의 연산을 +, -로 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    stack<int> st;
    vector<char> push_pop;
    int cur = 1;
    
    for(int i = 0; i < n; i++) {
        int num = nums[i];
        while(cur <= num) {
            push_pop.push_back('+');
            st.push(cur++);
        }
        
        if(num == st.top()) {
            push_pop.push_back('-');
            st.pop();
        }
        else {
            cout << "NO" << '\n';
            exit(0);
        }
    }
    
    for(int i = 0; i < push_pop.size(); i++) cout << push_pop[i] << '\n';
}
```
- 오름차순 수를 입력받을 `st`과 각각의 연산을 했던 과정을 저장할 `push_pop`
- 현재 수의 위치를 기억할 `cur`
- `cur`이 수열의 해당 번쨰인 `num`보다 작으면은 같아질 때까지 `st`에 넣으면서 1씩 증가시키며, 이 과정을 `push_pop`에 저장
- `st`의 상단 값이 `num`과 같으면은 `st`에서 값을 빼고, 이 과정을 `push_pop`에 저장
- 만일, 다르면은 `num`이 `st`에 중간에 있어서 **올바른 수열을 만들 수 없는 것**이므로 NO를 출력
- 위 과정들을 다 진행한 후에 `push_pop`에 있는 연산 과정인 +, -를 각각 출력
</details>

### 후기
- 문제 설명 참 그지같이 했네.