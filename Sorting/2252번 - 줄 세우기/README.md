### 2252번: 줄 세우기

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/2252)

**문제 조건**
- N명의 학생들을 키 순서대로 줄 세우기
- 모든 학생들의 키를 비교하는 것이 아닌 일부 학생 두 학생들만 서로 키를 비교
- 일부 학생들의 키를 비교한 결과를 통해 대략적인 N명의 학생들의 키 순서로 세우기  
_(※ 즉, 비교했던 학생들에 한해 대략적인 전체 키 순서만 맞으면은 됨. 전체학생들의 키 순서는 상관없음)_

**출력**  
- N명의 학생들이 앞에서부터 대략적인 작은 순서부터 큰 순서대로 줄 세운 결과를 출력  
_(※ 답이 여러 가지인 경우에는 아무거나 출력 가능)_

### 풀이
1. 이 문제는 대표적인 **위상 정렬 알고리즘** 문제이다.
2. 예를 들어, 3번이 1번보다 크고 3번이 2번보다 클 때 3번은 1번과 2번 뒤에 서야한다. 하지만 1번과 2번은 서로 비교한 적이 없으므로 나올 수 있는 답은 1 2 3 또는 2 1 3이다.
3. vector v에 a번째에 b값을 추가하고 b의 앞에는 적어도 비교한 만큼 있으므로 degree[b]++ 한다.
4. degree로 1번부터 n번째까지 확인하여 값이 0인 것을 queue에 저장
5. queue의 첫번째 값(가장 작은 키 학생)을 출력하고, 해당 학생과 비교했던 학생의 degree[next]--를 한다.
6. degree[next] 값이 0이면은 더이상 자기보다 작은 학생이 없는 것이므로 queue에 넣기
7. queue가 전부 빌 때까지 이를 반복 

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void input() {
    cin >> n >> m;
    v.resize(n + 1);
    degree.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!degree[i]) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        for(auto next : v[now]) {
            degree[next]--;
            if(!degree[next]) q.push(next);
        }
    }
}
```
- 코드 설명
</details>