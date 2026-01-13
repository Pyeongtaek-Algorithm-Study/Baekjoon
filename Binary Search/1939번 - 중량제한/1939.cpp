#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LIM 100001

bool visited[LIM];

// 도달 가능한지 확인하는 함수
bool bfs(int depart, int arrive, const int val, const vector<pair<int, int>> path[]) {
    fill(begin(visited), end(visited), false);  // 전역 visited 배열 초기화
    queue<int> Q;
    Q.push(depart);
    visited[depart] = true;
    
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        if (cur == arrive) {
	          return true;
	      }
        
        for (auto& p : path[cur]) {
            int nxt = p.first;
            int weight = p.second;
            
            if (weight < val || visited[nxt]) continue;
            visited[nxt] = true;
            Q.push(nxt);
        }
    }
    
    return false;
} 

void solve (int n, int m, const vector<pair<int, int>> path[], int fac_1, int fac_2) 
{
    int res = 0;
    int st = 1e9, end = -1;

    // 도로의 하중을 견딜 수 있는 최대, 최소 무게 구하기
    for (int i = 1; i <= n; i++) {  // 1부터 n까지
        for (auto& p : path[i]) {
            st = min(st, p.second); // 최소 하중
            end = max(end, p.second); // 최대 하중
        }
    }
    
    while (st <= end) {
        int mid = (st + end) / 2;
        
        if(bfs (fac_1, fac_2, mid, path)) {
            res = mid;
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, fac_1, fac_2;
    cin >> n >> m;

    vector<pair<int, int>> path[LIM];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }
    cin >> fac_1 >> fac_2;

    solve(n, m, path, fac_1, fac_2);
    return 0;
}
