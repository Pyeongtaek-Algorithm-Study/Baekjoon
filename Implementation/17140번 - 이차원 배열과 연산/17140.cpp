// 17140번 : 이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

int r, c, k;
int arr[MAX][MAX] = { 0, };

void input() {
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    r--;
    c--;
}

int change(int a, int b, bool is_row) {
    int count_num[MAX] = { 0, };
    int max_len = 0;
    
    for(int i = 0; i < a; i++) {
        fill_n(&count_num[0], MAX, 0);
        vector<pair<int, int> > bucket;
        
        for(int j = 0; j < b; j++) {
            if(is_row) {
                count_num[arr[i][j]]++;
            }
            else {
                count_num[arr[j][i]]++;
            }
        }
        
        for(int j = 1; j < MAX; j++) {
            if(count_num[j] > 0) {
                bucket.push_back({count_num[j], j});
            }
        }
        
        int len = bucket.size();
        max_len = max(max_len, len * 2);
        sort(bucket.begin(), bucket.end());
        int idx = 0;
        
        for(int j = 0; j < MAX; j++) {
            if(is_row) {
                arr[i][j] = 0;
            }
            else {
                arr[j][i] = 0;
            }
        }
        
        for(int j = 0; j < len; j++) {
            if(is_row) {
                arr[i][idx++] = bucket[j].second;
                arr[i][idx++] = bucket[j].first;
            }
            else {
                arr[idx++][i] = bucket[j].second;
                arr[idx++][i] = bucket[j].first;
            }
        }
    }
    return max_len;
}

void solve() {
    int h = 3, w = 3, t = 0;
    
    while(1) {
        if(arr[r][c] == k) {
            cout << t << '\n';
            break;
        }
        if(t > 100) {
            cout << -1 << '\n';
            break;
        }
        
        if(h >= w) {
            w = change(h, w, true);
        }
        else {
            h = change(w, h, false);;
        }       
        t++;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
