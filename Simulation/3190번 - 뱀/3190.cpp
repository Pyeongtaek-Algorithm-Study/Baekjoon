#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, k, l;
int board[101][101] = { 0, };
int apple[101][101] = { 0, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, char> > moves;

void input() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        apple[a][b] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        int a;
        char c;
        cin >> a >> c;
        moves.push({a, c});
    }
}

void show() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
}

void solve() {
    // 뱀의 위치 및 방향
    int x = 1, y = 1;
    int dir = 0;
    int sec = 0;
    
    // 뱀의 몸과 맵에서의 뱀
    board[1][1] = 1;
    queue<pair<int, int> > snake;
    snake.push({1, 1});
    
    while(1) {
        x += dx[dir];
        y += dy[dir];
        sec++;

        // 맵 밖으로 나가거나 몸을 부딪힘
        if(x <= 0 || x > n || y <= 0 || y > n || board[x][y]) break;
        
        // 머리 옮기기
        snake.push({x, y});
        board[x][y] = 1;
        
        // 사과가 있는지 확인
        if(apple[x][y]) {
            apple[x][y] = 0;
        }
        else {
            pair<int, int> tail = snake.front();
            board[tail.X][tail.Y] = 0;
            snake.pop();
        }
        
        // 맵에서의 뱀 이동하는 것 보기
        // show();
        
        int move_cnt = moves.front().X;
        int turn = (moves.front().Y == 'D' ? 1 : -1);
        if(sec == move_cnt) {
            dir = ((dir + turn + 4) % 4);
            moves.pop();
        }
    }
    
    cout << sec << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}