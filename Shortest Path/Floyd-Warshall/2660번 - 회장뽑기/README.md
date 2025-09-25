### 풀이
1. 각 노드에서 **다른 노드로 도착할 때까지의 거리**를 알아야 한다.
2. 회원 수는 50명 미만임으로, 3차 반복문을 해도 가능하여 `Floyd-Warshall` 알고리즘을 사용
3. 각 노드까지 도착하는 최단 거리가 있을 경우, 값을 갱신
4. 각 출발 노드에서 가장 최대 거리를 `distance[]` 배열에 저장
5. 점수가 가장 낮은 사람이 회장이 됨으로, `minValue`에 따라 후보의 거리값 저장
6. 구했던 `distance[]`에 구했던 `minValue`와 비교하여 후보자들을 순차적으로 대입

### 핵심 코드

<details>
<summary>코드 보기</summary>

```java
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] > map[i][k] + map[k][j]) {
                map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

int minValue = INF;
int[] distance = new int[n + 1];
for (int i = 0; i < n; i++) {
    int status = 0;
    for (int j = 0; j < n; j++) {
        status = Math.max(status, map[i][j]);
    }
    distance[i] = status;
    minValue = Math.min(minValue, status);
}
```
- 
</details>

### 후기
- `new`의 객체 생성
- `StringBuilder`를 통해서 출력