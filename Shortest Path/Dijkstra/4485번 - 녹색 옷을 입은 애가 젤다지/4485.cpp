// 4486번: 녹색 옷 입은 애가 젤다지?
#include <iostream>
#include <queue>

#define endl "\n"
#define MAX 126
#define INF 987654321
#define X first
#define Y second

using namespace std;

int n, ans;
int board[MAX][MAX] = {0, };
int vis[MAX][MAX] = {0, };

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dijkstra() {
    // 연속된 3개의 변수를 한번에 저장하는 그런 것은 struct로 만 가능한 듯
    // pq가 길다면은 처음부분에 음수로 저장하기.
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({board[0][0], {0, 0}});
    vis[0][0] = board[0][0];
    
    while(!pq.empty()) {
        int cost = pq.top().X;
        int x = pq.top().Y.X;
        int y = pq.top().Y.Y;
        pq.pop();
        
        if(cost > vis[x][y]) continue; 
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int ncost = cost + board[nx][ny];
            if ( vis[nx][ny] <= ncost) continue;
            vis[nx][ny] = ncost;
            pq.push(make_pair(vis[nx][ny], make_pair(nx, ny)));
        }
    }
}

void solution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            vis[i][j] = INF;
        }
    }
    dijkstra();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; ; i++) {
        cin >> n;
        if(!n) break;
        solution();
        cout << "Problem " << i << ": " << vis[n-1][n-1] << endl; 
    }
    
    return 0;
}