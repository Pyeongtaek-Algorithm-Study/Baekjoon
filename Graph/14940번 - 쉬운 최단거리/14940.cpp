// 14940번: 쉬운 최단거리
#include <iostream>
#include <queue>
#include <string.h> // for memset()

using namespace std;

#define MAX 1001
#define X first
#define Y second

int n, m;
int arr[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

queue <pair<int, int> > Q;

void BFS() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; 
            Q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(!arr[i][j]) dist[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 2) {
                Q.push({i, j});
                dist[i][j] = 0;
                BFS();
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}