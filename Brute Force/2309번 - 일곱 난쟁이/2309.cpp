#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 9;

int dwarf[CNT] = { 0, };
bool liar[CNT] = { false, };

void input() {
    for(int i = 0; i < CNT; i++) cin >> dwarf[i];
}

void find_lier(int sum) {
    for(int i = 0; i < CNT; i++) {
        for(int j = i + 1; j < CNT; j++) {
            if(dwarf[i] + dwarf[j] == sum) {
                liar[i] = true;
                liar[j] = true;
                return;
            }
        }
    }
}

void solve() {
    sort(dwarf, dwarf + CNT);
    
    int sum = 0;
    for(int i = 0; i < CNT; i++) sum += dwarf[i];
    sum -= 100;
    
    find_lier(sum);
    
    for(int i = 0; i < CNT; i++) {
        if(liar[i]) continue;
        cout << dwarf[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}