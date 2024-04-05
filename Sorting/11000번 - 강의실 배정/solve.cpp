#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define F first
#define S second

int N;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
  
    sort(v.begin(), v.end());
  
    for(auto it : v) {
        pq.push(it.S);
        if(pq.top() <= it.F) {
            pq.pop();         
        }
    }

    cout << pq.size();     

    return 0;
}
