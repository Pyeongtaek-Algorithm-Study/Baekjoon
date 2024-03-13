### 1991번: 트리 순회

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/1991)
2. **도움 블로그** : 

**문제 조건**
- 이진 트리를 입력 받음
- 노드의 개수 `N`과 2번째 줄부터 `N`개의 줄에 걸쳐 각 노드, 왼쪽 노드, 오른쪽 노드로 입력받음
- 루트노드는 항상 `A`, 자식 노드가 없을 시에는 `.`으로 표현

**출력**  
- 이진 트리가 주어졌을 때, **전위 순회, 중위 순회, 후위 순회를 출력**

### 풀이
1. 각각의 순회를 함수로 표현한다.
2. 각 순회는 재귀적으로 호출하여 탐색한다.
  1. 전위 순회는 출력 순서가 _루트노드 - 왼쪽 노드 - 오른쪽 노드_ 순이므로 함수가 호출될 때 즉시 해당 노드를 출력
  2. 중위 순위는 출력 순서가 _왼쪽 노드 - 루트노드 - 오른쪽 노드_ 순이므로 왼쪽 노드가 존재 시 계속하여 탐색하고 그 다음에 해당 노드를 출력
  3. 후위 순위는 출력 순서가 _왼쪽 노드 - 오른쪽 노드 - 루트노드_ 순이므로 왼쪽 노드를 탐색하고 그 다음 오른쪽 노드를 다 탐색하고 그 다음에 해당 노드를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void preorder(char node) {
    cout << node;
    int seq = node - 'A';
    if(tree[seq].first != '.') preorder(tree[seq].first);
    if(tree[seq].second != '.') preorder(tree[seq].second);
}

void inorder(char node) {
    int seq = node - 'A';
    if(tree[seq].first != '.') inorder(tree[seq].first);
    cout << node;
    if(tree[seq].second != '.') inorder(tree[seq].second);
}

void postorder(char node) {
    int seq = node - 'A';
    if(tree[seq].first != '.') postorder(tree[seq].first);
    if(tree[seq].second != '.') postorder(tree[seq].second);
    cout << node;
}
```
- 코드 설명은 생략
</details>

### 후기
- 단순하게 재귀하는 양식은 똑같으나 출력하는 순서에 따라 달라지는 것이 꽤나 신기했다.