#include <bits/stdc++.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 101

int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
int area[MAX][MAX];
int vis[MAX][MAX];

int n = 0;
int safety = 0;
queue<pair<int,int>> Q;

void BFS(int height) {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X][cur.Y] = 1;
        
        for(int dir = 0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if ( nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if ( area[nx][ny] <= height || vis[nx][ny] == 1 ) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

void reset() {
    safety = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            vis[i][j] = 0;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 1;
    int height = 0;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> area[i][j];
            height = max(height, area[i][j]);
        }
    }
    
    for(int h = 0; h<height;h++) { 
        for(int i = 0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(area[i][j] > h && vis[i][j] == 0) {
                    Q.push({i, j});
                    BFS(h);
                    safety++;
                }
            }
        }
        result = max(result, safety);
        reset();
    }
    
    cout << result << '\n';
    return 0;
}
