### 1197번: 최소 스패닝 트리

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1197)
2. **도움 블로그** : https://0m1n.tistory.com/80

**문제 조건**
- 그래프가 주어졌을 때, 노드와 간선을 제공
- **스패닝 트리는 모든 노드를 연결할 수 있는 간선의 개수가 노드 개수 - 1인 것**
- 최소 스패닝 트리는 스패닝 트리의 가능한 것들 중에서 **가중치의 합이 최소**인 것

**출력**  
- 입력 받은 그래프의 최소 스패닝 트리의 가중치 합이 최소인 값을 출력

### 풀이
1. 최소 스패닝 트리를 구하는 알고리즘에는 **크루스칼 또는 프림 알고리즘**이 존재
2. 현 풀이에서는 크루스칼 알고리즘으로 풀이
    1. 간선의 가중치를 기준으로 오름차순으로 정렬
    2. 가중치가 낮은 것을 기준으로 하나씩 선택
    3. 선택한 간선의 노드들이 사용이 되었는지 확인
    4. 2~3번 과정을 반복하며 간선을 확인하고 간선의 개수가 노드 개수의 -1 만큼될때 까지 반복
    5. 반복되는 과정에서 3번 과정으로 검토하면서 진행하며 최종적으로 노드 개수가 -1 개 일 때 모든 노드에 방문할 수 있는 간선을 선택
3. `tree`의 가중치값을 기준으로 오름차순 정렬
4. `min_weight`, `edge_cnt`는 각각 최소 스패닝 트리의 가중치 합, 간선의 개수를 의미
5. `edge` 벡터에서는 `tree`의 간선의 값을 저장
6. `Union-Find` 알고리즘으로 노드들의 집합을 확인하여 간선으로 사용될 수 있으면 하나로 합침

_간선에서 노드가 서로 연결되었음을 확인하기 위해 `parents` 배열로 `Union-Find` 알고리즘을 통해 확인_
7. 해당 간선이 사용되었으면, `min_weight`에 가중치 값을 합산
8. `edge_cnt` 값이 노드의 개수 -1 만큼 되었을 때 반복문을 종료하고 값을 출력

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
- `Union-Find` 알고리즘 사용
- `tree`의 가중치 값을 기준으로 오름차순으로 정렬
- `edge` 벡터에는 `tree`의 가중치 값이 낮은 것부터 순차적으로 대입
- `edge` 값의 시작과 도착 노드의 `parents` 값이 같으면은 하나의 집합으로 이미 사용된 노드라는 의미로 넘어감
- 노드의 부모가 서로 다르다면 아직 해당 노드 사이에 간선이 없는 것이므로 `Union` 함수로 하나의 집합으로 묶음
- `min_weight` 값에 해당 간선의 가중치 값을 합산
- `edge_cnt` 값이 노드 개수 -1 만큼 되었을 때 해당 스패닝 트리가 구현된 것이고 이때 가중치값이 최소인 것
</details>

### 후기
- 스패닝 트리라는 구조를 알아야했으며 새로운 알고리즘 기법인 **크루스칼**에 대해 알게 됨.
- 사이 간선으로 연결된 노드를 파악하기 위해 `Union-Find`로 하나의 집합으로 묶는 방식의 아이디어가 신기했음.