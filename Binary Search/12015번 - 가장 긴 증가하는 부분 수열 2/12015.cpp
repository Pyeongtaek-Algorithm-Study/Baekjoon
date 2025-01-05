#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> aes_num;

void input() {
    cin >> n;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
}

int lowerBound(vector<int> &num, int k) {
    int l = 0;
    int r = num.size() - 1;
    int half = r;
    
    while(l < r) {
        half = (l + r) / 2;
        
        if(k > num[half])
            l = half + 1;
        else
            r = half;
    }
    
    return r;
}

void solve() {
    int ans = 1;
    aes_num.push_back(v[0]);
    
    for(int i = 1; i < n; i++) {
        if(v[i] > aes_num.back()) {
            aes_num.push_back(v[i]);
            continue;
        }
        int idx = lowerBound(aes_num, v[i]);
        // int idx = lower_bound(aes_num.begin(), aes_num.end(), v[i]) - aes_num.begin(); // 내장함수
        aes_num[idx] = v[i];
    }
    
    cout << aes_num.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}