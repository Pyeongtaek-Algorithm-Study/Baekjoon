### 2623번: 음악프로그램

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/2623)
2. **도움 블로그** : 

**문제 조건**
- 뮤직 프로그램에 가수의 출연 순서가 존재
- 각 보조 PD들은 각자 담당한 가수의 출연 순서가 존재
- 보조 PD가 담당한 가수의 출연 순차적으로 해야 함. _뒷 번호가 앞 번호보다 먼저 나와선 안됨_
- 보조 PD들의 담당 가수의 일부 순서가 불가능할 경우도 존재

**출력**  
- 각 보조 PD들의 가수들의 출연 순서에 맞도록 모든 가수들을 순차적으로 출력
- 만일, 모든 조건에 만족하는 경우가 없으면 0을 출력

### 풀이
1. 순서가 존재하므로 위상정렬 알고리즘
2. 

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int cnt, a, b;
        cin >> cnt >> a;
        while(--cnt) {
            cin >> b;
            v[a].push_back(b);
            degree[b]++;
            a = b;
        }
    }
}
```
- 각 보조PD 마다 담당할 가수 명 수인 `cnt`, 각자 처음 순서 가수를 `a`에 저장
- 이후 다음 순서를 `b`에 저장 후, 위상정렬 알고리즘을 위해 `a`와 `b`의 관계들을 저장
- 이후 순서가 필요한 `b`를 개수 증가
- 이후 다음 순차일 때의 순서를 위해 `a` 값에 `b`를 저장

```cpp
void solve() {
    queue<int> q;
    vector<int> ans;
    
    for(int i = 1; i <= n; i++)
        if(degree[i] == 0) q.push(i);
        
    while(!q.empty()) {
        int now = q.front(); q.pop();
        ans.push_back(now);
        for(int i = 0; i < v[now].size(); i++) {
            int nxt = v[now][i];
            if(--degree[nxt] == 0) q.push(nxt);
        }
    }
    
    if(ans.size() == n) {
        for(int &it : ans) cout << it << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}
```
- 일반적인 _위상 정렬 알고리즘_ 과 동일
- 각 순서를 담을 `ans`를 선언하여 각 순서 가수들을 저장
- `ans`의 크기가 `n`과 다르면은 보조 PD들의 순서를 맞출 수 없는 경우가 있는 경우이므로 0을 출력
- `n`과 같으면은 모든 순서에 부합하는 **경우의 수**를 찾은 것이므로 각 가수들을 출력
</details>

### 후기
- 모든 조건을 만족할 수 없는 경우가 있다는 것을 빼먹어서 1번 틀리고 고침
- 개인적으로 _PS_ 를 생각해내는 것보다 `input`일 때 위상정렬을 위한 `vector`에 담는 생각이 더 어려웠었음.