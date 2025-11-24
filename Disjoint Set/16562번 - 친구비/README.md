### 16562번: 친구비

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/16562)
2. **도움 블로그** : https://growingegg.tistory.com/184

### 풀이
1. 친구들의 관계로 Union을 통해 그룹화
2. 그룹화 할 때 비용이 더 작은 값을 기준으로 그 그룹의 부모로 저장
3. 위 과정을 반복
4. 최종적으로 구한 각 그룹별 최솟값은 그 그룹에서 부모와 자기가 같은 학생이 대표
5. 그 대표들의 비용을 합산
6. 합산한 금액이 k 이하인지 확인하여 결과 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```java
public static void solve(List<int[]> list) {
    for (int[] tmp : list) {
        // Union
        int a = Find(tmp[0]);
        int b = Find(tmp[1]);
        if (a != b) {
            if (minCost[a] < minCost[b]) {
                parent[b] = a;
                minCost[b] = minCost[a];
            }
            else {
                parent[a] = b;
                minCost[a] = minCost[b];
            }
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // 해당 그룹의 부모의 비용만 합산
        if (parent[i] == i) {
            sum += minCost[i];
        }
    }
    
    // 전체 친구를 사귀기 위한 비용과 k값 비교 후 출력
    System.out.println(sum <= k ? sum : "Oh no");
}
```
</details>

### 후기
- 비용의 최솟값을 생각하는 것이 어려웠음
- 