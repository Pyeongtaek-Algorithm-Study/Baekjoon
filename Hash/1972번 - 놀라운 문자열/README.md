### 1972번: 놀라운 문자열

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/1972)

**문제 조건**
- 입력 문자열 길이 N에 대하여 문제에서 제시하는 0-쌍부터 N-2쌍까지의 각 쌍들에서 쌍들이 유일한지 파악
- 입력 문자열이 '*' 일 때 종료 

**출력**  
- 문자열의 각 쌍들이 유일할 떄 **[문자열] is surprising.**, 아닐 경우 **[문자열] is NOT surprising.** 출력

### 풀이
1. 문자열의 길이 `N`을 구한 후에, 문자열의 위치는 `pos`, 거리는 `i`로 구분
2. 각 쌍의 길이는 `i`로 반복문을 통해 유일한지 확인
3. `while`문을 통해 pos 위치 문자와 i번째 거리의 문자를 합쳐서 문자열 `sp`에 저장
4. `map`을 이용해 해당 문자열이 존재하는지 확인한 후, 없으면 `map`에 저장
5. 만일, 존재하면 문자열에서 해당 **i-쌍**은 유일한 것이 아니므로 _is NOT surprising._ 으로 출력
6. `i` 값이 N-2쌍까지 반복   

### 핵심 코드

```
for(int i = 1; i < len; i++) {
    int pos = 0;
    map<string, int> m;
    
    while(1) {
        if(pos+i > len-1) break;
        
        string sp;
        sp = str[pos];
        sp += str[pos+i];

        if(m.find(sp) != m.end()) ans = " is NOT surprising.";
        else m.insert(make_pair(sp, 1));
        
        pos++;
    }
}

```
- 0-쌍은 문자 사이 거리가 1이므로 `i` 값을 1로 시작 하고, 문자열 길이 `len`까지 반복 
> **N-2 쌍까지는 결국 `len-1` 길이까지 쌍들이 유일한지 확인하는 것**이므로 `i < len` 까지의 비교문과 같음
- `pos+i` 값이 문자열 내의 위치를 초과하는지 확인
- 문자열에서 `pos` 위치 문자와 `pos+i` 위치 문자를 `sp`에 저장
- `map` 에서 문자가 있는지 확인한 후, 없다면 map에 저장 / 존재한다면, 유일하지 않으므로 _NOT surprising._ 이 출력되게 저장
- `pos++` 하여 해당 쌍에서 문자열의 다음 쌍 찾기 반복
