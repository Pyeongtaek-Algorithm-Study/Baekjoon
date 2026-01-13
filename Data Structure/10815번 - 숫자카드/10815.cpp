#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

#define LIM 500001

int n, m;
vector<int> haveNum;
vector<int> findNum;

void input() {
    cin >> n;
    haveNum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> haveNum[i];
    }
    
    cin >> m;
    findNum.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> findNum[i];
    }
}

void solve() {
    sort(haveNum.begin(), haveNum.end());
    
    for (int x : findNum) {
        cout << (binary_search(haveNum.begin(), haveNum.end(), x) ? 1 : 0) << " ";
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