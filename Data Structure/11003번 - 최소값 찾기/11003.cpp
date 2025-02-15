#include <iostream>
#include <queue>
#include <deque>

using namespace std;

#define MAX 5000001

int n, l;
int num[MAX];

void input() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
}

void solve_pq() {
    priority_queue<pair<int, int>> pq;
    
    for(int i = 0; i < n; i++) {
        pq.push({-num[i], i});
        
        while(pq.top().second <= (i - l) && !pq.empty()) pq.pop();
        
        cout << -pq.top().first << ' ';
    }
}

void solve_dq() {
    deque<pair<int, int> > dq;
    
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front().second <= (i - l)) dq.pop_front();
        while(!dq.empty() && dq.back().first > num[i]) dq.pop_back();
        
        dq.push_back({num[i], i});
        
        cout << dq.front().first << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    // solve_pq();
    solve_dq();
    
    return 0;
}