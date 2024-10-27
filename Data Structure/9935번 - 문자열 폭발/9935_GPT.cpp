#include <iostream>
#include <string>

using namespace std;

string str, bomb;

void input() {
    cin >> str >> bomb;
}

void solve() {
    int bomb_len = bomb.length();
    string result = "";
    
    for(char &c : str) {
        result += c;
        
        if(result.size() >= bomb_len && result.substr(result.size() - bomb_len, bomb_len) == bomb) {
            result.erase(result.size() - bomb_len, bomb_len);
        }
    }
    
    cout << (result.length() ? result : "FRULA") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
