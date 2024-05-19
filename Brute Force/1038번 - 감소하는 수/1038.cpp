// 1038번: 감소하는 수
#include <iostream>
#include <queue>

#define endl "\n"
#define MAX 1000001

using namespace std;

int n;
long long dp[MAX];

void bruteforce() {
    queue<long long> q;
    
    for(int i = 1; i <= 9; i++) {
        q.push(i);
        dp[i] = i;
    }
    
    if(0 <= n && n <= 10) {
        cout << n << endl;
    }
    
    int idx = 10;
    while(idx <= n && !q.empty()) {
        long long num = q.front();
        q.pop();
        
        int last = num % 10;
        for(int i = 0; i < last; i++) {
            q.push(num * 10 + i);
            dp[idx++] = num * 10 + i;
        }
    }

    if(dp[n]) cout << dp[n] << endl;
    else cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    bruteforce();
    
    return 0;
}