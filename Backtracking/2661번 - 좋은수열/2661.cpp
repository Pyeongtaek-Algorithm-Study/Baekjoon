// 2661번: 좋은 수열
#include <iostream>

using namespace std;

int n;
string res = "";
bool finish = false;

void input() {
    cin >> n;
}

bool isbad(string s) {
    int len = s.length();
    int half = len / 2;
    
    for(int i = 1; i <= half; i++) {
        string front = s.substr(len - (i * 2), i); 
        string back = s.substr(len - i, i); 
        if(front == back) return true;
    }
    return false;
}

void backtrackging(string s, int len) {
    if(isbad(s)) return;
    if(len == n) {
        res = s;
        cout << res << "\n";
        exit(0);
    }
    backtrackging(s + "1", len + 1);
    backtrackging(s + "2", len + 1);
    backtrackging(s + "3", len + 1);
}

void solve() {
    backtrackging(res, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}