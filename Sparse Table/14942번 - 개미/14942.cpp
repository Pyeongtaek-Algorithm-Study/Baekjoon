#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001
#define LOG 18
#define X first
#define Y second

int n, energys[MAX];
vector<pair<int, int> > path[MAX];

// i에서 2^j로 이동 후 정점과 필요 에너지
int parents[MAX][LOG];
int dist[MAX][LOG]; 

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> energys[i];
    for(int i = 0, a, b, c; i < n - 1; i++) {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }
}

void dfs(int curNode, int preNode) {
    parents[curNode][0] = preNode;
    
    for(int i = 0; i < path[curNode].size(); i++) {
        int nxtNode = path[curNode][i].X;
        
        if(nxtNode != preNode) {
            dist[nxtNode][0] = path[curNode][i].Y;
            dfs(nxtNode, curNode);
        }
    }
}

void sparse_table() {
    // i섬에서 2^j 이동했을 때의 필요 에너지와 상위 노드 값 테이블 저장
    for(int j = 1; j < LOG; j++) {
        for(int i = 1; i <= n; i++) {
            dist[i][j] = dist[i][j-1] + dist[parents[i][j-1]][j-1];
            parents[i][j] = parents[parents[i][j-1]][j-1];
        }
    }
    
    // 각각의 개미들이 가지고 있는 에너지로 도달할 수 있는 방 출력
    for(int i = 1; i <= n; i++) {
        int pos = i, energy = energys[i];
        for(int j = LOG - 1; j >= 0; j--) {
            if(parents[pos][j] != 0 && energy >= dist[pos][j]) {
                energy -= dist[pos][j];
                pos = parents[pos][j];
            }
        }
        cout << pos << '\n';
    }
}

void solve() {
    dfs(1, 0);
    
    sparse_table();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}