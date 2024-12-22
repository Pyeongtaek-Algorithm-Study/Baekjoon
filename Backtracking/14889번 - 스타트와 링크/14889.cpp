#include <iostream>

using namespace std;

int n;
int soccer[21][21];
bool vis[21];
int ans = 201;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> soccer[i][j];
        }
    }
}

void back(int cur, int l) {
    if(l == n / 2) {
        int pt1 = 0, pt2 = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i] == true && vis[j] == true) pt1 += soccer[i][j];
                if(vis[i] == false && vis[j] == false) pt2 += soccer[i][j];
            }
        }
        
        ans = min(ans, abs(pt1 - pt2));
        return;
    }

    for(int i = cur + 1; i < n; i++) {
        vis[i] = true;
        back(i, l + 1);
        vis[i] = false;
    }
}

void solve() {
    back(0, 0);
    
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}