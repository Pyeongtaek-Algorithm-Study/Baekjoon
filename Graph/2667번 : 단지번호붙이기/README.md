### 2667번: 단지번호 붙이기

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/2667)

**문제 조건**
- 정사각형 모양의 지도(N * N 배열)
- 1은 집이 있는 곳, 0은 집이 없는 곳을 나타내며, 1이 상하좌우로 연결되어 있는 것을 연결로 의미
- 집끼리 연결되어 있는 구역을 하나의 단지

**목적**  
단지 수를 출력한 후, 각 단지 내의 집의 갯수를 오름차순으로 출력

### 풀이
- 입력을 띄어쓰기 구분없이 입력받기 때문에 문자열로 입력받고 문자하나씩 정수형으로 변환 후 배열에 입력  
`board[i][j] = str[j] - '0'`
- 단지 내의 집의 갯수를 오름차순으로 정렬하기 위해 `priority_queue<int, vector<int>, greater<int>> arr` 이용  
- BFS를 돌면서 단지 내에 연결되어 있는 집들을 찾을 때마다 `area++`하고, 단지의 시작위치를 찾을 때 마다 큐(`Q`)에 저장하고 `num++`를 함

### 핵심 코드
<details>
<summary>코드 살펴보기</summary>

```
	priority_queue<int, vector<int>, greater<int>> arr;
	int num = 0; 
	for(int i =0; i<n; i++) {
		for(int j = 0; j< n; j++) {
			if(board[i][j] == 0 || vis[i][j]) continue;
			num++;
			queue<pair<int,int> > Q;
			vis[i][j] = 1;
			Q.push({i, j});
			int area = 0;
			while(!Q.empty()) {
				area++; //단지의 넓이를 재기
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir =0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny <0 || ny >= n) continue;
					if(vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			arr.push(area);
		}
	} 
```

1. `i, j`을 통해 배열을 순회하며 if문으로 **board의 값이 0이거나 방문을 했을 때**는 다음 순회로 넘어간다.
2. 단지의 시작 위치를 발견하면, 큐를 생성한 후 방문했음을 표시하기 위해 `vis[i][j] = 1`로 저장
3. `nx, ny`는 해당 배열의 위치에서 상하좌우의 값을 의미한다. 이때 **board 배열을 벗어나지 않고, 방문했거나 집이 아닌경우는 제외**한 위치를 큐에 넣으며 큐가 비워질 때 까지 반복
4. 최종적으로, `num`은 단지의 수를 의미하고, `area`는 단지 내의 집의 갯수를 오름차순 큐에 넣어서 정렬된다.

</details>
