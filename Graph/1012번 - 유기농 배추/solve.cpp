#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

int T, M, N, K;
int cnt;
int farm[51][51];
int vis[51][51];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(pair<int, int> p) {
    vis[p.X][p.Y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = p.X + dx[i];
        int ny = p.Y + dy[i];
        if(nx < 0 || nx > M || ny < 0 || ny > N) continue;
        if(farm[nx][ny] && !vis[nx][ny]) dfs({nx, ny}); 
    }
}

void init() {
    cnt = 0;
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            farm[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        init();
        for(int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < N; k++) {
                if(farm[j][k] && !vis[j][k]) {
                    cnt++;
                    dfs({j, k});
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}