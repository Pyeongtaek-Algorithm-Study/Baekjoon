#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define X first
#define Y second

int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char grid[MAX][MAX];
bool visited[MAX][MAX];
char color[3] = {'R', 'G', 'B'};

int nomal = 0, weak = 0;
queue<pair<int, int> > Q;

void bfs(char c) {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        visited[cur.X][cur.Y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx > N || ny < 0 || ny > N) continue;
            if( grid[nx][ny] != c || visited[nx][ny] ) continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        strncpy(grid[i], str.c_str(), str.length());
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(auto it : color) {
                if(grid[i][j] == it && !visited[i][j]) {
                    Q.push({i, j});
                    bfs(it);
                    nomal++;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 'R') grid[i][j] = 'G';
            visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(auto it : color) {
                if(grid[i][j] == it && !visited[i][j]) {
                    Q.push({i, j});
                    bfs(it);
                    weak++;
                }
            }
        }
    }
    
    cout << nomal << " " << weak << "\n";
    return 0;
}