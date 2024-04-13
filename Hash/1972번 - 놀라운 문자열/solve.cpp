#include<bits/stdc++.h>

using namespace std;

string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> str;
        if(str == "*") break;
        
        string ans = " is surprising.";
        int len = str.length();
        
        for(int i = 1; i < len; i++) {
            int pos = 0;
            map<string, int> m;
          
            while(1) {
                if(pos+i > len-1) break;
                
                string sp;
                sp = str[pos];
                sp += str[pos+i];
     
                if(m.find(sp) != m.end()) ans = " is NOT surprising.";
                else m.insert(make_pair(sp, 1));
                
                pos++;
            }
        }
        cout << str << ans << '\n';
    }
    return 0;
}
