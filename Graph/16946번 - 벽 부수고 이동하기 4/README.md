### 16946번: 벽 부수고 이동하기 4

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/16946)
2. **도움 블로그** : 
    - https://nim-code.tistory.com/253
    - https://velog.io/@mechauk418/%EB%B0%B1%EC%A4%80-16946%EB%B2%88-%EB%B2%BD-%EB%B6%80%EC%88%98%EA%B3%A0-%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B04-%ED%8C%8C%EC%9D%B4%EC%8D%ACDFS

**문제 조건**
- N X M으로 이루어진 행렬로 표현되는 맵
- 각 칸에는 0 또는 1로 이뤄줬으며, 0은 이동가능하며 1은 이동불가한 벽을 나타냄
- 이동할 때는 0이로 이뤄진 칸에 서로 변이 공유할 때 이동 가능하며, 이동 가능 경로는 해당 칸 기준으로 상하좌우
- **벽의 규칙**
    - 해당 칸의 벽을 부수고, 이동 가능한 칸으로 변경
    - 그 위치에서 **이동가능한 칸의 개수를 셈**

**출력**  
- 맵의 형태로 출력하며, 0인 곳은 0을 출력하고 1이였던 벽의 칸은 **이동 가능 칸의 개수를 10으로 나눈 나머지**를 출력

### 풀이
1. C++은 _BFS_ 로, Python은 _DFS_ 로 풀었으며, 풀이는 _DFS_ 기준으로 설명
2. 0인 칸이며 방문하지 않은 곳일 때, 해당 구역의 번호를 지정하고 _DFS_ 를 진행하여, 이동 가능 개수를 구함  
_구역 번호는 음수로 -1부터 시작하여 점차 내려감_
3. 만일 벽인 경우에는 벽들의 좌표를 집합으로 따로 모음
4. 맵의 _DFS_ 를 다 확인 한 후에는 각 구역의 이동가능 칸을 **키-값** 형태로 저장
5. 모아뒀던 벽들을 하나씩 확인하여 상하좌우를 살펴봐서 각 구역이 있는지 확인
6. 인접한 구역이 있으면은 리스트에 담아놓으며 **중복된 구역**을 없앰
7. 해당 벽에 각 구역의 이동가능 칸들의 합을 더한 후 최종 값에 10의 나머지를 저장
9. 각 과정을 마무리한 후, **구했던 각 칸들의 값**을 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```py
def dfs(x, y, cnt, area_num):
    vis[x][y] = True
    area_arr[x][y] = area_num
    
    for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
        nx = x + dx
        ny = y + dy
        
        if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
            if arr[nx][ny] == 0:
                cnt = max(cnt, dfs(nx, ny, cnt + 1, area_num))

    return cnt
```
- `dfs()`로 시작 위치인 `x`, `y`와 이동가능 칸 수인 `cnt`, `area_num`인 해당 구역의 번호를 입력받음
- 탐색을 진행하면서 0이면서 방문하지 않은 곳일 때 탐색하며 `cnt` 값을 비교하여 이동 가능 경로의 최댓값을 구함

```py
def solve():
    area_dict = dict()
    area = -1
    walls = []
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0 and not vis[i][j]:
                t = dfs(i, j, 1, area)
                area_dict[area] = t
                area -= 1
            elif arr[i][j] == 1:
                walls.append([i, j])
    
    for wall in walls:
        x = wall[0]
        y = wall[1]
        ans_list = []
        
        for dx, dy in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < n and 0 <= ny < m and area_arr[nx][ny] < 0:
                ans_list.append(area_arr[nx][ny])
                
        ans_list = list(set(ans_list))
        
        # divide 10
        for el in ans_list:
            arr[x][y] += area_dict[el]
        arr[x][y] %= 10
    
    # answer
    for i in arr:
        print(''.join(map(str, i)))
```
- 구역과 이동 가능 칸 수를 키-값 형태로 입력받기 위한 `area_dict` 선언
- `area`로 0의 범위에 영역 번호를 지정 하고 벽인 경우 좌표를 저장하기 위한 `wall` 
- 해당 칸이 0이면서 방문하지 않은 곳에 `dfs()` 하여 이동가능한 칸의 개수를 찾은 후, 영역 번호와 함께 저장
- 벽인 경우를 하나씩 살펴봐서 해당 칸의 상하좌우를 확인 후에 주변에 영역의 번호를 확인하여 `set()`을 통해 중복을 제거
- 중복 제거 후, 영역에 대한 값들을 해당 칸에 합산
- 이후에, 해당 칸의 값을 10의 나머지로 저장
- 해당 맵을 출력하여 정답 확인
</details>

### 후기
- C++ 풀이에서 _BFS_ 를 한 후에 방문했던 벽을 다시 `false`로 돌리는 것이 참신했다.
- 벽을 기준으로 _BFS_ 를 돌면은 시간초과 발생 `vis[][]` 를 다시 초기화하면서 해야하므로 0을 확인하여 `vis[][]` 초기화하지 않도록 하는 것이 관건