#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int x, int y) {
        if(abs(x) == abs(y)) {
            return x > y;
        }
        else return abs(x) > abs(y);
    }
};

int n, x;
priority_queue<int, vector<int>, cmp> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 0) {
            if(pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n"; 
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}