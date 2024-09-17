#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int arr[8];
bool vis[8];


void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(vis, vis + n, false);
    v.resize(m);
}

void backtracking(int idx, int cnt) {
    if(cnt == 0) {
        for(auto it : v) cout << it << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            v[idx] = arr[i];
            backtracking(idx + 1, cnt - 1);
            vis[i] = false;
        }
    }
}

void solve() {
    sort(arr, arr + n);
    backtracking(0, m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}