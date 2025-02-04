#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;
int map[1001][1001];
bool vis[1001][1001];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            map[i][j] = str[j] - '0';
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    vector<pair<int, int> > wall;
    
    Q.push({x, y});
    vis[x][y] = true;
    int cnt = 1;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]) continue;
            
            if(map[nx][ny] == 0) {
                cnt++;
                Q.push({nx, ny});
            }
            else {
                wall.push_back({nx, ny});
            }
            vis[nx][ny] = true;
        }
    }
    
    for(auto &it : wall) {
        map[it.X][it.Y] += cnt;
        vis[it.X][it.Y] = false;
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0 && !vis[i][j]) bfs(i, j);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] % 10;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}