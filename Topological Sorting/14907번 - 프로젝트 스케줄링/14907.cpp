#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

#define LIM 27

int degree[LIM] = { 0, }, t[LIM] = { 0, };
vector<int> order[LIM];

vector<string> split(string st, char del) {
    istringstream iss(st);
    string buffer;
    
    vector<string> res;
    
    while(getline(iss, buffer, del)) {
        res.push_back(buffer);
    }
    
    return res;
}

void input() {
    string str;
    
    while(getline(cin, str)) {
        vector<string> res = split(str, ' ');
        int alpha = res[0][0] - 'A';
        
        t[alpha] = stoi(res[1]);
        
        if(res.size() > 2) {
            for(auto &c : res[2]) {
                order[c - 'A'].push_back(alpha);
                degree[alpha]++;
            }
        }
    }
}

void solve() {
    int min_time[LIM] = { 0, };
    
    queue<int> Q;
    for(int i = 0; i < LIM; i++) {
        if(degree[i] == 0 && t[i]) {
            Q.push(i);
            min_time[i] = t[i];
        }
    }
    
    while(!Q.empty()) {
        int now = Q.front(); Q.pop();

        for(int &nxt : order[now]) {
            min_time[nxt] = max(min_time[nxt], min_time[now] + t[nxt]);
            
            if(--degree[nxt] == 0) Q.push(nxt);
        }
    }
    
    cout << *max_element(min_time, min_time + LIM) << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}