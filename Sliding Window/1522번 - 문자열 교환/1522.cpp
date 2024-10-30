#include <iostream>
#include <string>

using namespace std;

string str = "";
int ret = 1000;

void input() {
    cin >> str;
}

void solve() {
    int a_cnt = 0;
    int str_len = str.length();
    
    for(char a : str) {
        if(a == 'a') a_cnt += 1;
    }
    
    for(int i = 0; i < str_len; i++) {
        int b_cnt = 0;
        for(int j = 0; j < a_cnt; j++) {
            if(str[(i + j) % str_len] == 'b') b_cnt += 1;
        }
        ret = min(ret, b_cnt);
    }
    
    cout << ret << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}