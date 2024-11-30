### 1197번: 최소 스패닝 트리

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1197)
2. **도움 블로그** : https://0m1n.tistory.com/80

**문제 조건**
- 그래프가 주어졌을 때, 노드와 간선을 제공
- 스패닝 트리는 모든 노드를 연결할 수 있는 간선의 개수가 노드 개수 - 1인 것
- 최소 스패닝 트리는 스패닝 트리의 가능한 것들 중에서 가중치의 합이 최소인 것

**출력**  
- 입력 받은 그래프의 최소 스패닝 트리의 가중치 합이 최소인 값을 출력

### 풀이
1. 문제 풀이 설명

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
int Find(int a) {
    if(parents[a] == a) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parents[b] = a;
}

void solve() {
    sort(tree.begin(), tree.end());
    
    int min_weight = 0;
    int edge_cnt = 0;
    
    for(int i = 0; i < tree.size(); i++) {
        // edge value is weight(c), start(a), end(b)
        vector<int> edge = tree[i];
        
        if(Find(edge[1]) == Find(edge[2])) continue;
        Union(edge[1], edge[2]);
        
        min_weight += edge[0];
        
        if(++edge_cnt == v - 1) break;
    }
    
    cout << min_weight << '\n';
}
```
- 코드 설명
</details>

### 후기
- 