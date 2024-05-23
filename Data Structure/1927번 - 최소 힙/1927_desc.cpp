#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i< n; i++) {
        int tmp;
        cin >> tmp;
        if(!tmp) {
            if(pq.empty()) cout << 0 << "\n";
            else {
                int t = pq.top(); pq.pop();
                cout << -t << "\n";
            }
        }
        else {
            pq.push(-tmp);
        }
    }
    
    return 0;
}