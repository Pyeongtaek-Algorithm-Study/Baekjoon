#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int> > gem;
vector<int> bag;

void input() {
    cin >> n >> k;
    for(int i = 0, m, v; i < n; i++) {
        cin >> m >> v;
        gem.push_back({m, v});
    }
    for(int i = 0, tmp; i < k; i++) {
        cin >> tmp;
        bag.push_back(tmp);
    }
}

void solve() {
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());
    
    long long ans = 0;
    int idx = 0;
    
    priority_queue<int> pos_weight;
    
    for(int i = 0; i < k; i++) {
        while(idx < n && gem[idx].first <= bag[i]) {
            pos_weight.push(gem[idx].second);
            idx++;
        }
        
        if(pos_weight.size()) {
            int w = pos_weight.top(); pos_weight.pop();
            ans += w;
        }
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