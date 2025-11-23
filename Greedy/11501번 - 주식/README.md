### 11501번: 주식

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/11501)
2. **도움 블로그** : 

### 풀이
1. 최대 수익의 최악의 수의 값이 int형을 넘어섬
2. 배열의 뒷 부분 부터 탐색하여 현재 저장된 값보다 크면 값을 갱신
3. 저장된 값과 현재 배열의 위치의 값을 비교하여 작다면은 주식으로 돈을 벌 수 있는 것임으로 차이 값을 sum에 합산
4. 위 과정을 반복하여 배열의 시작 위치까지 반복

### 핵심 코드

<details>
<summary>코드 보기</summary>

```java
public static void solve(int[] arr, int len) {
    
    long sum = 0;
    int max = -1;
    
    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] <= max) {
            sum += (max - arr[i]);
        }
        else {
            max = arr[i];
        }
    }
    
    System.out.println(sum);
}
```
</details>

### 후기
- int형이 아닌 long 타입이라는 것에 주의 해야 함.

