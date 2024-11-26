#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> k;
string min_ans = "987654321";
string max_ans = "0";

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        k.push_back(tmp);
    }
}

void recursive(string num, int arr[10]) {
    int len = num.length() - 1;
    if(len >= n) {
        min_ans = min(min_ans, num);
        max_ans = max(max_ans, num);
        return;
    }
    
    for(int i = 0; i < 10; i++) {
        if(arr[i]) continue;
        
        if((k[len] == '>' && num[len] - '0' > i) || (k[len] == '<' && num[len] - '0' < i)) {
            num += to_string(i);
            arr[i] = 1;
            recursive(num, arr);
            arr[i] = 0;
            num = num.substr(0, num.length() - 1);
        }
    }
}

void solve() {
    for(int i = 0; i < 10; i++) {
        string s = to_string(i);
        int chk[10] = { 0, };
        chk[i] = 1;
        recursive(s, chk);
    }
    
    cout << max_ans << '\n';
    cout << min_ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}