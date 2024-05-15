// 14891번 : 톱니바퀴
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string gear[6];
int k;
vector<pair<int, int> > v;
bool vis[6];

void rotation(int idx, int d) {
    if(idx < 1 || idx > 4) return;
    if(vis[idx]) return;
    
    vis[idx] = true;

    if(d > 0) {
        gear[idx] = gear[idx][7] + gear[idx].substr(0, 7);
        // lefe gear
        if(gear[idx][7] != gear[idx - 1][2]) // 6 -> 7
            rotation(idx - 1, -d);
        // right gear
        if(gear[idx][3] != gear[idx + 1][6]) // 2 -> 3
            rotation(idx + 1, -d);
    }
    else {
        gear[idx] = gear[idx].substr(1, 7) + gear[idx][0];
        // lefe gear
        if(gear[idx][5] != gear[idx - 1][2]) // 6 -> 5
            rotation(idx - 1, -d);
        // right gear
        if(gear[idx][1] != gear[idx + 1][6]) // 2 -> 1
            rotation(idx + 1, -d);
    }
}

void solution() {
    int res = 0;
    gear[0] = "00000000";
    gear[5] = "00000000";
    
    for(int i = 0; i < k; i++) {
        int gear_num = v[i].first;
        int gear_dir = v[i].second;
        
        rotation(gear_num, gear_dir);
        for(int i = 1; i < 5; i++) vis[i] = false; 
    }
    
    for(int i = 1; i < 5; i++) {
        if(gear[i][0] == '1') {
            res += pow(2, i - 1);
        }
    }
    
    cout << res << "\n";
}

void input() {
    for(int i = 1; i < 5; i++)
        cin >> gear[i];
    cin >> k;
    for(int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        v.push_back({num, dir});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solution();
    
    return 0;
}