// 1946번 - 신입 사원

#include <bits/stdc++.h>

using namespace std;

int T, N, x, y;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            pq.push({x, y});
        }

        pair<int, int> p;
        int ans = 1;
        int tmp = pq.top().second;
        while(!pq.empty()) {
            p = pq.top(); pq.pop();
            if(p.second < tmp) {
                tmp = p.second;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}