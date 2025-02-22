#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> get_pi(string p) {
    int len = p.length();
    vector<int> table(len, 0);
    
    int j = 0;
    for(int i = 1; i < len; i++) {
        while(j > 0 && p[i] != p[j]) j = table[j-1];
        if(p[i] == p[j]) table[i] = ++j;
    }
    
    return table;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    vector<int> table = get_pi(p);
    int s_len = s.length();
    int p_len = p.length();
    int j = 0;
    
    for(int i = 0; i < s_len; i++) {
        while(j > 0 && s[i] != p[j]) j = table[j-1];
        if(s[i] == p[j]) {
            if(j == p_len - 1) {
                ans.push_back(i - p_len + 2);
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    
    return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, p;
	getline(cin, s);
	getline(cin, p);
    
	vector<int> matched = kmp(s, p);
	cout << matched.size() << '\n';
	for(auto i : matched) cout << i << ' ';

	return 0;
}