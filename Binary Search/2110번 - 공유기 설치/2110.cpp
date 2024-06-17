// 2110번: 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> house;

void input() {
    cin >> n >> c;
    
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    
    sort(house.begin(), house.end());
}

void solve() {
    int start = 1;
    int end = house[n - 1] - house[0];
    int result = 0;
    
    while(start <= end) {
        int mid = (start + end) / 2;
        int current = house[0];
        int count = 1;
        
        for(int i = 1; i < n; i++) {
            if(house[i] >= current + mid) {
                count++;
                current = house[i];
            }
        }
        
        if(count >= c) {
            start = mid + 1;
            result = mid;
        }
        else end = mid - 1;
    }
    
    cout << result << '\n';
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}