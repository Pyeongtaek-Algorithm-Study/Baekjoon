#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> pipe;

void input() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pipe.push_back(tmp);
    }
}

void solve() {
    sort(pipe.begin(), pipe.end());
    
    int tape = 0, len = 0;
    
    for(int i = 0; i < n; i++) {
        if(pipe[i] > len) {
            len = pipe[i] + l - 1;
            tape++;
        }
    }
    
    cout << tape << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}