### 1138번: 한 줄로 서기

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1138)
2. **도움 블로그** : https://mjmjmj98.tistory.com/63

**문제 조건**
- N명의 사람들이 매일 아침 한 줄을 서며, 자리를 마음대로 서지 못하고 오민식의 지시대로 섬.
- 사람들은 자신이 줄 서는 위치를 규칙으로 기록해 놓으며, 기록해 놓은 것과 사람들이 줄 선 위치가 맞는지 확인
- 사람들은 **자기보다 큰 사람이 왼쪽에 몇 명 있었는지**만 기억
- 각 순차적으로 키가 1번부터 N번 사람들이 기억하는 명수를 입력 받음

**출력**  
- 사람들이 줄을 선 순서대로 **키**를 출력

### 풀이
1. 줄을 왼쪽에서부터 선다고 하면, 어떤 사람이 왼쪽을 봤을 때 사람이 없는 사람부터 순차적으로 선다.
2. 이후 어떤 사람이 섰을 때 자기보다 작은 사람들이 오른쪽에 서게됨으로, 작은 사람들이 보는 명 수를 1씩 감소
3. 위 과정을 선 사람들을 체크하면서 진행하여 모든 사람이 설 때까지 반복

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    // 내 풀이
    for(int i = 1; i <= n; i++) {
        
        // 1번부터 n번까지 0인 값 찾기
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && height[j] == 0) {
                cout << j << ' ';
                
                // 방문 처리 후, 자기보다 낮은 사람 값 낮추기
                vis[j] = true;
                while(j--) if(height[j]) height[j]--;
                
                break;
            }
        }
    }
}
```
- `n`명의 사람들을 줄을 왼쪽에서 오른쪽으로 서야함으로 반복
- 왼쪽부터 차례대로 서는 위치에서 `vis[]`로 서지 않은 사람이며, `height[]`이 0으로 왼쪽을 봤을 때 없는 사람부터 섬.
- 해당 차례에서 선 사람은 체크를 하고 선 사람보다 키가 작은 사람들은 이제 우측에 서게 됨으로 사람이 보이게 됨으로, 각 키의 명수들을 1씩 감소
- 이후, 과정들을 계속 반복하여 `n`명의 사람들이 각자 자기 위치를 차례대로 출력되게 됨.
</details>

### 후기
- 블로그는 낮은 키 사람부터 섰지만, 내 방법으론 왼쪽부터 오른쪽으로 순서대로 서는 사람들 찾는 걸로 풀었음.