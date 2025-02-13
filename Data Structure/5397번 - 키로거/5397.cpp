#include <iostream>
#include <vector>
#include <list>

using namespace std;

int tc;
string logger;

void input() {
    cin >> logger;
}

void solve() {
    list<char> ans;
    list<char>::iterator cursor = ans.begin();
    
    for(char &c : logger) {
        if(c == '<') {
            if(cursor != ans.begin()) cursor--;
        }
        else if(c == '>') {
            if(cursor != ans.end()) cursor++;
        }
        else if(c == '-') {
            if(cursor != ans.begin()) cursor = ans.erase(--cursor);
        }
        else {
            cursor = ans.insert(cursor, c);
            cursor++;
        }
    }
    
    for(auto &it : ans) {
        cout << it;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
    
    return 0;
}