#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int p, m;
queue<pair<int, string> > Q;

void input() {
    cin >> p >> m;
    for(int i = 0; i < p; i++) {
        int l;
        string n;
        cin >> l >> n;
        Q.push({l, n});
    }
}

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}

void solve() {
    vector<pair<int, string> > room[301];
    int cnt = 0;
    while(!Q.empty()) {
        pair<int, string> cur = Q.front(); Q.pop();
        bool check = true;
        for(int i = 0; i < cnt; i++) {
            if(cur.first <= room[i][0].first + 10 && cur.first >= room[i][0].first - 10) {
                if(room[i].size() < m) {
                    room[i].push_back(cur);
                    check = false;
                    break;
                }
            }
        }
        if(check) {
            room[cnt].push_back(cur);
            cnt++;
        }
        
    }
    for(int i = 0; i < cnt; i++) {
        cout << (room[i].size() >= m ? "Started!" : "Waiting!") << '\n'; 
        sort(room[i].begin(), room[i].end(), compare);
        for(auto it : room[i]) {
            cout << it.first << " " << it.second << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}