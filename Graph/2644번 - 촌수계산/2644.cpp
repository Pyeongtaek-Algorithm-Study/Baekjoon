#include <iostream>
#include <vector>

using namespace std;

int n, m;
int family[101][101];
bool vis[101][101];
int st, en;

void input() {
    cin >> n >> st >> en >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        family[x][y] = 1;
        family[y][x] = 1;
    }
}

void dfs(int s, int depth) {
    if(s == en) {
        cout << depth << '\n';
        exit(0);
    }
    for(int i = 0; i <= n; i++) {
        if(family[s][i] && !vis[s][i]) {
            vis[s][i] = true;
            vis[i][s] = true;
            dfs(i, depth + 1);
        } 
    }
}

void solve() {
    dfs(st, 0);
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}