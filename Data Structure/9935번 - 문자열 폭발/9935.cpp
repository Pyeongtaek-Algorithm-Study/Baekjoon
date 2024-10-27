#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, bomb;
    cin >> str >> bomb;
    
    int bomb_len = bomb.length();
    string result = "";
    stack<char> S;
    
    for(int i = str.length() - 1; i >= 0; i--) {
        S.push(str[i]);
        if(S.top() == bomb[0]) {
            string tmp = "";
            tmp += S.top(); S.pop();
            bool chk = false;
            for(int j = 1; j < bomb_len && !S.empty(); j++) {
                if(S.top() != bomb[j]) {
                    chk = true;
                    break;
                }
                tmp += S.top(); S.pop();
            }
            if(chk || tmp.length() != bomb_len) {
                for(int j = tmp.length() - 1; j >= 0 ; j--) {
                    S.push(tmp[j]);
                }
            }
        }
    }
    while(!S.empty()) {
        result += S.top(); S.pop();
    }
    cout << (result.length() ? result : "FRULA") << '\n';
    
    return 0;
}