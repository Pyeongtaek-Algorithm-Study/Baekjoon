#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int n, k, t, m;
vector<int> vv;
vector<vector<int> > logs;

void input() {
    cin >> n >> k >> t >> m;
    
    logs.clear();
    for(int i = 0, a, b, s; i < m; i++) {
        cin >> a >> b >> s;
        logs.push_back({a, b, s});
    }
}

bool cmp(pair<pair<int, int>, pair<int, int> > &t1, pair<pair<int, int>, pair<int, int> > &t2) {
    if(t1.X.Y == t2.X.Y) {
        if(t1.Y.X == t2.Y.X) {
            return t1.Y.Y < t2.Y.Y;
        }
        return t1.Y.X < t2.Y.X;
    }
    return t1.X.Y > t2.X.Y;
}

void problem_solve_1() {
    int points[n + 1][k + 1] = { 0, };
    pair<pair<int, int>, pair<int, int> > team[n + 1];
    
    for(int i = 1; i <= n; i++) {
        team[i].X.X = i;
    }
    
    for(int i = 0; i < logs.size(); i++) {
        int id = logs[i][0], pid = logs[i][1], score = logs[i][2];
        
        if(points[id][pid] < score) {
            team[id].X.Y -= points[id][pid];
            points[id][pid] = score;
            team[id].X.Y += points[id][pid];
        }
        team[id].Y.X += 1;
        team[id].Y.Y = i;
    }
    
    sort(team + 1, team + (n + 1), cmp);
    for(int i = 1; i <= n; i++) {
        if(team[i].X.X == t) {
            cout << i << '\n';
            break;
        }
    }
}

void problem_solve_2() {
    int cnt[101] = { 0, };
    int last[101] = { 0, };
    int points[101][101] = { 0, };
    vector<vector<int> > teams;
    
    for(int i = 0; i < logs.size(); i++) {
        int id = logs[i][0], qid = logs[i][1], score = logs[i][2];
        points[id][qid] = max(points[id][qid], score);
        cnt[id]++;
        last[id] = i;
    }
    
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        
        for(int j = 1; j <= k; j++) sum += points[i][j];
        teams.push_back({-sum, cnt[i], last[i], i});
    }
    
    sort(teams.begin(), teams.end());
    
    for(int i = 0; i < n; i++) {
        if(teams[i][3] == t) {
            cout << i + 1 << '\n';    
        }
    }
}

void solve() {
    // 직접 cmp를 구현
    // problem_solve_1();
    
    // sort를 통해 매개값에 음수를 곱해서 원하는 정렬 구현
    problem_solve_2();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
    
    return 0;
}