// 1987번 - 알파벳
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[21][21];

int r, c, ans = 1;
bool alpha[26];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y, int cnt) {
    ans = max(ans, cnt);
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(alpha[board[nx][ny] - 'A']) continue;
        alpha[board[nx][ny] - 'A'] = true;
        dfs(nx, ny, cnt + 1);
        alpha[board[nx][ny]-'A'] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    alpha[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    
    cout << ans << '\n';
    return 0;
}