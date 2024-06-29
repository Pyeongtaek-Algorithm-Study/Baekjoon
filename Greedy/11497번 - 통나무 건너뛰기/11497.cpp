// 11497: 통나무 건너뛰기
#include <iostream>
#include <algorithm> // for sort()
#include <vector>

using namespace std;

int t = 0;
vector<vector<int>> v;

void input() {
    cin >> t;
    while(t--) {
        int n = 0;
        vector<int> v2;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            v2.push_back(tmp);
        }
        sort(v2.begin(), v2.end(), greater<int>());
        v.push_back(v2);
    }
}

void solve() {
    for(vector<int> it : v) {
        int M = 0;
        for(int i = 0; i < it.size() - 2; i++) {
            M = max(M, abs(it[i] - it[i + 2]));
        }
        cout << M << "\n";
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
