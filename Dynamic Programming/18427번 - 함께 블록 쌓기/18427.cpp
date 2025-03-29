#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n, m, h;
vector<int> students[51];
int dp[51][1001] = { 0, };
int ans = 0;

void input() {
    cin >> n >> m >> h;
    cin.ignore();
    
    for(int i = 1; i <= n; i++) {
        string tmp;
        getline(cin, tmp);
        
        istringstream iss(tmp);
        string buffer;
        
        while(getline(iss, buffer, ' ')) {
            students[i].push_back(stoi(buffer));
        }
    }    
}

void solve() {
    // i번째 학생이 높이 0을 만드는 경우의 수
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        // i번째 학생이 쌓을 수 있는 높이들
        for(int j = 1; j <= h; j++) {
            // i번째 학생이 가진 블럭들
            for(auto &k : students[i]) {
                if(j >= k) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= 10007;
                }
            }
            
            // i번째 학생이 블럭을 사용안해도 가능한 경우의 수도 더함
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 10007;
        }
    }
    
    cout << dp[n][h] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}