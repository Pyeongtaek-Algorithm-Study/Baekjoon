#include <iostream>
#include <unordered_map>

using namespace std;

#define LIM 200001

int tc, f;
unordered_map<string, int> fr;
unordered_map<int, int> p_cnt;
int parents[LIM];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--) {
        fr.clear();
        p_cnt.clear();
        int s = 0;
        
        cin >> f;
        for(int i = 0; i <= LIM; i++) parents[i] = i;
        
        for(int i = 0; i < f; i++) {
            string a_fr, b_fr;
            cin >> a_fr >> b_fr;
            if(fr.count(a_fr) == 0) {
                fr.insert({a_fr, s});
                p_cnt.insert({s++, 1});
            }
            if(fr.count(b_fr) == 0) {
                fr.insert({b_fr, s});
                p_cnt.insert({s++, 1});
            }
            
            Union(fr[a_fr], fr[b_fr]);
            
            cout << p_cnt[Find(fr[a_fr])] << '\n';
        }
    }
    
    return 0;
}