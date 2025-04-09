#include <iostream>
#include <vector>

using namespace std;

int n;
int height[11] = { 0, };
bool vis[11] = { false, };

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> height[i];
    }
}

void solve() {
    // 내 풀이
    for(int i = 1; i <= n; i++) {
        
        // 1번부터 n번까지 0인 값 찾기
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && height[j] == 0) {
                cout << j << ' ';
                
                // 방문 처리 후, 자기보다 낮은 사람 값 낮추기
                vis[j] = true;
                while(j--) if(height[j]) height[j]--;
                
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}