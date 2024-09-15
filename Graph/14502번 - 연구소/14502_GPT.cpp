#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, ans = 0;
int lab[8][8], after_lab[8][8];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> lab[i][j];
}

void dfs(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i], nc = c + dy[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && after_lab[nr][nc] == 0) {
            after_lab[nr][nc] = 2;
            dfs(nr, nc);
        }
    }
}

int simulate() {
    memcpy(after_lab, lab, sizeof(lab));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (after_lab[i][j] == 2)
                dfs(i, j);

    int safe_zone = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (after_lab[i][j] == 0)
                safe_zone++;

    return safe_zone;
}

void solve() {
    vector<int> spaces;
    for (int i = 0; i < n * m; ++i)
        if (lab[i / m][i % m] == 0)
            spaces.push_back(i);

    int len = spaces.size();
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
            for (int k = j + 1; k < len; ++k) {
                lab[spaces[i] / m][spaces[i] % m] = 1;
                lab[spaces[j] / m][spaces[j] % m] = 1;
                lab[spaces[k] / m][spaces[k] % m] = 1;

                ans = max(ans, simulate());

                lab[spaces[i] / m][spaces[i] % m] = 0;
                lab[spaces[j] / m][spaces[j] % m] = 0;
                lab[spaces[k] / m][spaces[k] % m] = 0;
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
