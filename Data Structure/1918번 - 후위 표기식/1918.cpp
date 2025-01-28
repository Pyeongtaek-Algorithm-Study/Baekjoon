#include <iostream>
#include <stack>

using namespace std;

string infix = "";

void input() {
    cin >> infix;
}

int pri(char ch) {
    switch(ch) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void solve() {
    stack<char> S;
    char st_top;
    
    for(int i = 0; i < infix.length(); i++) {
        char cur_w = infix[i];
        if(cur_w == '(')
            S.push(cur_w);
        else if(cur_w == ')') {
            st_top = S.top(); S.pop();
            while(st_top != '(') {
                cout << st_top;
                st_top = S.top(); S.pop();
            }
        }
        else if(cur_w == '+' || cur_w == '-' || cur_w == '*' || cur_w == '/') {
            while(!S.empty() && (pri(cur_w) <= pri(S.top()))) {
                st_top = S.top(); S.pop();
                cout << st_top;
            }
            S.push(cur_w);
        }
        else {
            cout << cur_w;
        }
    }
    
    while(!S.empty()) {
        cout << S.top(); S.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}