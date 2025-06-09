#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<string> files;
map<string, int> ext_cnt;

void input() {
    cin >> n;
    
    string tmp = "";
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        files.push_back(tmp);
    }
}

vector<string> split(string str, char del) {
    istringstream iss(str);
    string buffer;
    
    vector<string> result;
    
    while(getline(iss, buffer, del)) {
        result.push_back(buffer);
    }
    
    return result;
}

void solve() {
    for(string &file : files) {
        // solve_1
        // vector<string> split_str = split(file, '.');
        
        // // 확장자를 따로 저장한다.
        // string ext = split_str[1];
        
        // solve_2
        string ext = file.substr(file.find('.') + 1);
        
        
        if(ext_cnt.find(ext) != ext_cnt.end()) {
            ext_cnt[ext]++;
        }
        else {
            ext_cnt.insert({ext, 1});
        }
    }
    
    for(auto &[ext_w, ext_c] : ext_cnt) {
        cout << ext_w << ' ' << ext_c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}