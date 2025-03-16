#include <iostream>
#include <stack>

using namespace std;

string pare;
stack<char> st;

void input() {
    cin >> pare;
}

void solve() {
    int ans = 0, tmp = 1;
    char pre = ' ';
    
    for(int i = 0; i < pare.length(); i++) {
        if(pare[i] == '(') {
            st.push(pare[i]);
            tmp *= 2;
        }
        else if(pare[i] == '[') {
            st.push(pare[i]);
            tmp *= 3;
        }
        else if(pare[i] == ')') {
            if(st.empty() || st.top() == '[') {
                ans = 0;
                break;
            }
            
            st.pop();
            
            if(pre == '(') ans += tmp;
            tmp /= 2;
        }
        else if(pare[i] == ']') {
            if(st.empty() || st.top() == '(') {
                ans = 0;
                break;
            }
            
            st.pop();
            
            if(pre == '[') ans += tmp;
            tmp /= 3;
        }
        
        pre = pare[i];
    }
    
    cout << (st.empty() ? ans : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}