// 1043번: 거짓말
#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int truth[51];
int parent[51];
vector<int> party[51];

void input() {
    cin >> n >> m >> t;
    for(int i = 0; i < t; i++) {
        cin >> truth[i];
    }
    for(int i = 0; i < m; i++) {
        int size;
        cin >> size;
        for(int j = 0; j < size; j++) {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }
    for(int i = 0; i < n; i++) parent[i] = i;
}

int Find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) parent[b] = a;
}

void solve() {
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < party[i].size(); j++) {
            Union(party[i][0], party[i][j]);    
        }
    }
    
    int res = m;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < t; j++) {
            if(Find(party[i][0]) == Find(truth[j])) {
                res--;
                break;
            }
        }
    }
    
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}