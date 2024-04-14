#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char seat[5][5];
int vis[5][5], board[5][5];
int ans = 0;
int pos[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                1, 1, 1, 1, 1, 1, 1};
bool bfs(vector<pair<int, int>> v) { 
    fill(&vis[0][0], &vis[4][5], 0);
    fill(&board[0][0], &board[4][5], 0);
    
    for(auto c : v) board[c.x][c.y] = 1;
   
    queue<pair<int, int>> q;
    q.push({v[0].x, v[0].y});
    vis[v[0].x][v[0].y] = 1;
    
    while(!q.empty()){       
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){            
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }    
        
    }     
    for(auto c : v)   
        if(vis[c.x][c.y] == 0) return false;
    return true;

}

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++) {        
        string s;
        cin >> s;
        for(int j = 0; j < 5; j++){            
            seat[i][j] = s[j];
        }    
    }     
    do {        
        vector<pair<int, int>> v;
   
        for(int i = 0; i < 25; i++) {            
            if(pos[i] == 1) v.push_back({(i / 5), (i % 5)});
        }         
        bool conn = bfs(v);
       
        if(conn) {            
            int cnt = 0;
            for(auto c : v) if(seat[c.x][c.y] == 'S') cnt++;
            if(cnt >= 4) ans++;
        }    
    } while(next_permutation(pos, pos+25));
    
    cout << ans;
    return 0;
}
