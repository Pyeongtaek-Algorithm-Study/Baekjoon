#include <iostream>

using namespace std;

int h, w;
int block[501];

void input() {
    cin >> h >> w;
    for(int i = 0; i < w; i++) {
        cin >> block[i];
    }
}

void solve() {
    int ans = 0;
    
    for(int i = 0; i < w; i++) {
        int left = 0, right = 0;
        
        for(int j = 0; j < i; j++) left = max(left, block[j]);
        for(int j = i + 1; j < w; j++) right = max(right, block[j]);
        if(left == 0 || right == 0) continue;
        
        int rain = min(left, right);
        if(rain > block[i]) ans += rain - block[i];
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}