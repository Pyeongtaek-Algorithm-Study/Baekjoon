### 17298번: 오큰수

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/17298)

**문제 조건**
- 각 원소 $A_i$에 대해서 오큰수 NGE(i)를 구하려고 한다.  
※ $A_i$의 오른쪽의 있는 자기보다 큰 수들중에서 가장 왼쪽에 있는 수 

**출력**  
- N인 수열에서 각 자리의 NGE()을 수를 찾아서 출력, 만일 해당 자리에 NGE() 수가 없을 시에는 -1 출력

### 풀이
1. 이중 반복문을 통해서 문제의 답을 출력할 수 있지만 수열의 크기가 1000000이므로 시간초과 발생
2. NGE()의 각 자리의 값을 저장하기 위헤 ans[]을 -1로 초기화
3. stack<int> s를 선언한 후에, 초기 idx인 0을 push
4. n번째까지 반복하기 위해 for문을 한 후, stack이 비어있지 않고, 현재 n번째 값이 arr[s.top()] 값 보다 크면은 오큰수를 발견할 것이므로 해당 수를 n번째 ans[]에 저장
5. pop()을 한 후, 다음 번째 NGE()를 구하기 위해 stack에 n번째 idx를 push
6. 최종적인 반복문이 끝난 후에는 ans[]의 값들을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
  s.push(0);
  
  for(int i = 0; i < n; i++) {
    while(!s.empty() && (arr[s.top()] < arr[i])) {
      ans[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }
    
  for(int i = 0; i < n; i++) 
    cout << ans[i] << " ";
}
```
- stack s에 초기 idx인 0을 push
- i번째 NGE() 값을 구하기 위해 stack에 저장된 idx위치의 arr값과 arr[i]값을 비교
- arr[i]값이 더 클 경우 stack에 저장된 idx의 NGE() 값이 arr[i]가 되므로 ans[i]번째에 값 저장
- stack에 저장된 idx번째의 NGE()를 구했으므로 stack에서 pop을 하고, i번째 순서를 stack에 push
- 최종적으로 반복해서 최종 ans[]에 저장된 결과값들 출력 
</details>

### 후기
> 