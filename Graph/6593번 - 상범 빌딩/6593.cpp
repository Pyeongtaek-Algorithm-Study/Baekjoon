#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int l, r, c;
char building[31][31][31];
int vis[31][31][31];

int dx[6] = {0, -1, 0, 1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

queue<vector<int>> Q;

void solve() {
    while(!Q.empty()) {
        int z = Q.front()[0];
        int y = Q.front()[1];
        int x = Q.front()[2];
        Q.pop();
        
        if(building[z][y][x] == 'E') break;
        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l) continue;
            if(building[nz][ny][nx] == '#' || vis[nz][ny][nx]) continue; 
            vector<int> n_tmp = {nz, ny, nx};
            Q.push(n_tmp);
            vis[nz][ny][nx] = vis[z][y][x] + 1;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> l >> r >> c;
        if(!l && !r && !c) exit(0);
        
        int st_z, st_y, st_x;
        int end_z, end_y, end_x;
        
        while (!Q.empty()) {
            Q.pop();
        }
        
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    cin >> building[i][j][k];
                    vis[i][j][k] = 0;
                    if(building[i][j][k]=='S') {
                        st_x = k;
                        st_y = j;
                        st_z = i;
                    }
                    if(building[i][j][k]=='E') {
                        end_x = k;
                        end_y = j;
                        end_z = i;
                    }
                }
            }
        }
        vis[st_z][st_y][st_x] = 0;
        vector<int> tmp_v = {st_z, st_y, st_x};
        Q.push(tmp_v);
        solve();
        if(vis[end_z][end_y][end_x]) cout << "Escaped in " << vis[end_z][end_y][end_x] << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    return 0;
}