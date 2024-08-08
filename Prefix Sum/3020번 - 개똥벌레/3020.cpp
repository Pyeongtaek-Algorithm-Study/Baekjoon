// 3020번: 개똥벌레
#include <iostream>
#include <vector>

using namespace std;

int n, h;
vector<int> up, down;
vector<int> result;
void input() {
    cin >> n >> h;
    down.resize(h + 1);
    up.resize(h + 1);
    result.resize(h + 1);
    for(int i = 0; i < n / 2; i++) {
        int a, b;
        cin >> a >> b;
        down[a]++;
        up[h + 1 - b]++;
    }
}

void solve() {
    for(int i = h - 1; i >= 1; i--) down[i] += down[i + 1];
    int min_num = 987654321;
    int cnt = 0;
    for(int i = 1; i <= h; i++) {
        up[i] += up[i - 1];
        result[i] += up[i] + down[i];
        if(result[i] < min_num) {
            cnt = 1;
            min_num = result[i];
        }
        else if(result[i] == min_num) cnt++;
    }
    
    cout << min_num << " " << cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    return 0;
}