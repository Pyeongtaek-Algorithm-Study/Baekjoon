#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int LIM = 51;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, m;
int lab[LIM][LIM];
int visited[LIM][LIM];
int virus = 0;
int ans = INF;
vector<pair<int, int>> coor;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == 2) {
                virus++;
                coor.push_back({i, j});
            }
        }
    }
}

int bfs(const vector<int> &v) {
    queue<pair<int, int>> Q;
    fill_n(&visited[0][0], LIM * LIM, -1);
    int spread_time = 0;

    for(int i = 0; i < virus; i++) {
        if(v[i]) {
            Q.push(coor[i]);
            visited[coor[i].first][coor[i].second] = 0;
        }
    }

    while(!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(lab[nx][ny] == 1 || visited[nx][ny] != -1) continue;
            
            visited[nx][ny] = visited[x][y] + 1;
            if(lab[nx][ny] == 0) spread_time = max(spread_time, visited[nx][ny]);
            Q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(lab[i][j] == 0 && visited[i][j] == -1)
                return INF;

    return spread_time;
}

void solve() {
    vector<int> v(virus, 0);
    fill(v.end() - m, v.end(), 1);
    
    do {
        ans = min(ans, bfs(v));
    } while(next_permutation(v.begin(), v.end()));
    
    cout << (ans != INF ? ans : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
