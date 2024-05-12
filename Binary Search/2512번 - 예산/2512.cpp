#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> m;
    sort(v.begin(), v.end());
    
    int st = 0;
    int end = v[n-1];
    while(st <= end) {
        int total = 0;
        int mid = (st + end) / 2;
        for(auto it : v) total += min(mid, it);
        
        if(total <= m) st = mid + 1;    
        else end = mid - 1;
    }
    cout << end << "\n";
    return 0;
}