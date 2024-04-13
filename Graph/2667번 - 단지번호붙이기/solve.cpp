#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int board[26][26];
bool vis[26][26];

int n;
string str;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i=0;i<n;i++) {
		cin >> str;
		for(int j=0; j<n; j++) {
			board[i][j] = str[j] -'0';
		}
	}
	
	// queue의 정렬(오름차순)
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
	cout << num << '\n'; //arr.size() 로 해도 무관
	while(!arr.empty()) {
		cout << arr.top() << '\n';
		arr.pop();
	}
	return 0;
}
