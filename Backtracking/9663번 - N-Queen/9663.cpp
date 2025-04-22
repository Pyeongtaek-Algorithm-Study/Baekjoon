#include <iostream>
#include <vector>

using namespace std;

int n;
int col[16] = { 0, };
int ans = 0;

void input() {
    cin >> n;
}

// 해당 칸의 비숍을 놓을 때 같은 열에 비숍이 있는지 또는 대각선에 비숍이 있는지 확인
bool check(int x) {
    for(int i = 0; i < x; i++) {
        if(col[x] == col[i] || abs(col[x] - col[i]) == x - i) {
            return false;
        }
    }
    
    return true;
}

void back(int x) {
    if(x == n) {
        ans++;
        return;
    }
    
    // 각 행에서 비숍을 놓음.
    for(int i = 0; i < n; i++) {
        col[x] = i;
        
        // 해당 칸에 비숍을 놓을 수 있는지 확인
        if(check(x)) {
            back(x + 1);
        }
    }
}

void solve() {
    back(0);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}