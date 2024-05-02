// 14499번 : 주사위 굴리기
#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
int board[21][21];
vector<int> dice(6); // Top, bottom, up, down, left, rigth

// east, west, north, south
bool can_move(int order) {
    int nx = x;
    int ny = y;
    switch(order) {
        case 1:
            ny++;
            break;
        case 2:
            ny--;
            break;
        case 3:
            nx--;
            break;
        case 4:
            nx++;
            break;
    }
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
    else {
        x = nx;
        y = ny;
        return true;
    }
}

// east, west, north, south
void roll_dice(int order) {
    // Copy the dice array to the tmp_dice array
    vector<int> tmp_dice = dice;
    
    switch(order) {
        case 1:
            dice[0] = tmp_dice[4]; // left -> right
            dice[1] = tmp_dice[5]; // right -> bottom
            dice[4] = tmp_dice[1]; // bottom -> left
            dice[5] = tmp_dice[0]; // top -> right
            break;
        case 2:
            dice[0] = tmp_dice[5]; // right -> top
            dice[1] = tmp_dice[4]; // left -> bottom
            dice[4] = tmp_dice[0]; // top -> left
            dice[5] = tmp_dice[1]; // bottom -> right
            break;
        case 3:
            dice[0] = tmp_dice[3]; // down -> top
            dice[1] = tmp_dice[2]; // up -> bottom
            dice[2] = tmp_dice[0]; // top -> up
            dice[3] = tmp_dice[1]; // bottom -> down
            break;
        case 4:
            dice[0] = tmp_dice[2]; // up -> top
            dice[1] = tmp_dice[3]; // down -> bottom
            dice[2] = tmp_dice[1]; // bottom -> up
            dice[3] = tmp_dice[0]; // top -> down
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int com;
    while(k--) {
        cin >> com;
        // Check if the dice can move.
        if(!can_move(com)) continue;
        
        roll_dice(com);
        
        if(board[x][y]) {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }
        else {
            board[x][y] = dice[1];
        }
        // top dice output
        cout << dice[0] << "\n";
    }
    
    return 0;
}