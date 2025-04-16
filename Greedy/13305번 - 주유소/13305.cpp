#include <iostream>

using namespace std;

#define LIM 100001
#define ll long long

int n;
int road[LIM], gas_station[LIM];

void input() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> road[i];
    for(int i = 0; i < n; i++) cin >> gas_station[i];
}

void solve() {
    int p1 = 0, p2 = 0;
    ll ans = 0;
    
    while(++p1 < n) {
        ll dist = 0;
        for(int i = p1; i < n; i++) {
            // i가 마지막 도시에 도착하면은 p1을 마지막 도시에 가리킴
            if(i == n - 1) p1 = n - 1;
            dist += road[i - 1];
            
            // i번쨰 도시 주요소 값이 p2 주요소 값보다 작거나 같을 때 해당 마을을 p1으로 가리킴
            if(gas_station[i] <= gas_station[p2]) {
                p1 = i;
                break;
            }
        }
        
        // 출발 도시에서 다음 도시까지만 기름 충전
        ans += (gas_station[p2] * dist);
        p2 = p1;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}