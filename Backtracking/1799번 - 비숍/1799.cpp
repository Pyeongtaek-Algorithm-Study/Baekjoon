#include <iostream>

using namespace std;

#define MAX 11

int n;
int board[MAX][MAX] = {0,};
int tmp[MAX][MAX] = {0, }; 
int ans[2] = {0, };
int l[20] = {0, }, r[20] = {0, };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void show(int max_cnt, int cnt) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << tmp[i][j];
        }
        cout << '\n';
    }
    cout << "max_cnt : "<<max_cnt << ", cnt : " << cnt << "\n\n";
}

void tracking(int row, int col, int cnt, int color) {
    if(col >= n) {
        row++;
        if(col % 2 == 0) col = 1;
        else col = 0;
    }
    if(row >= n) {
        ans[color] = max(ans[color], cnt);
        // show(ans[color], cnt);
        return;
    }
    
    
    if(board[row][col] && !l[col - row + n - 1] && !r[row + col]) {
        l[col - row + n - 1] = r[row + col] = 1;
        // tmp[row][col] = color + 1;
        tracking(row, col + 2, cnt + 1, color);
        l[col - row + n - 1] = r[row + col] = 0;
        // tmp[row][col] = 0;
    }
    tracking(row, col+2, cnt, color);
}

void solve() {
    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);
      
    cout << ans[0] + ans[1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}