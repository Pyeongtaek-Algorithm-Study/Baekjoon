// 4486번: 녹색 옷 입은 애가 젤다지?
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 126
#define X first
#define Y second

int n, e;
int board[MAX][MAX];
int vis[MAX][MAX];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

// void showBoard() {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << vis[i][j] << ' ';
//         }
//         cout << endl;
//     }
// }

void BFS() {
    queue<pair<int,int> > Q;
    Q.push({0, 0});
    vis[0][0] = board[0][0];
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if ( vis[nx][ny] <= vis[cur.X][cur.Y] + board[nx][ny]) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + board[nx][ny];
            Q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k = 1;
    n = 1;
    
    while(true) {
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
                vis[i][j] = 100000000;
            }
        }
        BFS();
        cout << "Problem " << k << ": " << vis[n-1][n-1] << endl;
        k++;
    }
    
    return 0;
}