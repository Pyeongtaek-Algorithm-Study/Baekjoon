// 10816번: 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cards;
vector<int> amounts;

void input() {
    cin >> n;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        cards.push_back(tmp);
    }
    
    cin >> m;
    for(int i = 0, tmp; i < m; i++) {
        cin >> tmp;
        amounts.push_back(tmp);
    }
}

void solve() {
    sort(cards.begin(), cards.end());
    
    for(int amount : amounts) {
        int st_idx = lower_bound(cards.begin(), cards.end(), amount) - cards.begin();
        int end_idx = upper_bound(cards.begin(), cards.end(), amount) - cards.begin();
        cout << end_idx - st_idx << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}