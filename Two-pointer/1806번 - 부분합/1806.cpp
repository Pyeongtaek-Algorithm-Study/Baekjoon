#include <iostream>

using namespace std;

int n, s;
int seq[100001] = { 0, };

void input() {
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> seq[i];
}

void solve() {
    int st = 0, end = 0;
    int sum = seq[0];
    int ans = 1e9;
    
    while(st <= end && end < n) {
        if(sum < s) {
            end++;
            sum += seq[end];
        }
        else {
            ans = min(ans, end - st + 1);
            sum -= seq[st];
            st++;
        }
    }
    
    cout << (ans != 1e9 ? ans : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}