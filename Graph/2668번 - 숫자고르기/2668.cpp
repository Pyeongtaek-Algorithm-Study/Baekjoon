#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[2][101];
vector<int> res;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[1][i];
    }
}

void recursive(int st, int val) {
    if(arr[0][val]) {
        if(st == val) res.push_back(st);
        return;
    }
    arr[0][val] = 1;
    recursive(st, arr[1][val]);
}

void solve() {
    for(int i = 1; i <= n; i++) {
        fill_n(&arr[0][0], 101, 0);
        arr[0][i] = 1;
        recursive(i, arr[1][i]);
    }
    cout << res.size() << '\n';
    for(int &it : res) cout << it << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}