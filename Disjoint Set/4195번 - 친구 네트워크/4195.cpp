#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define LIM 200001

int tc, f;
vector<pair<string, string> > con;
unordered_map<string, int> fr;
unordered_map<int, int> p_cnt;
int parents[LIM];

void input() {
    fr.clear();
    p_cnt.clear();
    con.clear();
    
    for(int i = 0; i <= LIM; i++) parents[i] = i;
    
    cin >> f;
    for(int i = 0; i < f; i++) {
        string a_fr, b_fr;
        cin >> a_fr >> b_fr;
        con.push_back({a_fr, b_fr});
    }
}

int Find(int a) {
    if(a == parents[a]) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) {
        parents[b] = a;
        p_cnt[a] += p_cnt[b];    
    }
}

void solve() {
    int s = 0;
    
    for(pair<string, string> &p : con) {
        string a = p.first;
        string b = p.second;
        
        if(fr.count(a) == 0) {
            fr.insert({a, s});
            p_cnt.insert({s++, 1});
        }
        if(fr.count(b) == 0) {
            fr.insert({b, s});
            p_cnt.insert({s++, 1});
        }
        Union(fr[a], fr[b]);
        
        cout << p_cnt[Find(fr[a])] << '\n';
    }
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