#include <iostream>
#include <vector>

using namespace std;

int g, p;
vector<int> airplane;
int parents[100001];

void input() {
    cin >> g >> p;
    for(int i = 0, tmp; i < p; i++) {
        cin >> tmp;
        airplane.push_back(tmp);
    }
    
    for(int i = 1; i <= g; i++) {
        parents[i] = i;
    }
}

int Find(int x) {
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) parents[y] = x;
}

void solve() {
    int ans = 0;
    
    for(int i = 0; i < p; i++) {
        int dock = Find(airplane[i]);
        if(dock == 0) break;
        
        Union(dock - 1, dock);
        ans++;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}