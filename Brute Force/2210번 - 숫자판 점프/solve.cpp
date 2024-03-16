#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[5][5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> ss;

void dfs(pair<int, int> cur, int cnt, int value) {
    if(cnt == 6) {
        ss.push_back(value);
        return;
    }
    else {
        for(int j = 0; j < 4; j++) {
            int nx = cur.X + dx[j];
            int ny = cur.Y + dy[j];
            if(nx < 0 || nx >=5 || ny < 0 || ny >= 5) continue;
            dfs({nx, ny}, cnt+1, value * 10 + board[cur.X][cur.Y]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            dfs({i, j}, 0, 0);
        }
    }

    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    cout << ss.size();
    
    return 0;
}