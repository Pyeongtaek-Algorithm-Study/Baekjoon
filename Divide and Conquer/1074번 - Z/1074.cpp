// 1074번: Z
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::ios;

#define endl '\n'

int n, r, c;
int ans;

void input() {
    cin >> n >> r >> c;
}


int recur(int N, int R, int C) {
    if(!N) return 0;
    return 2 * (R%2) + (C%2) + 4*recur(N-1, R/2, C/2);
}

void soloution_1() {
    while(n--) {
        int half = pow(2, n);
        int value = pow(half, 2);
        
        if(r < half && c < half) {
            ans += value * 0;
        }
        else if(r < half && c >= half) {
            ans += value * 1;
            c -= half;
        }
        else if(r >= half && c < half) {
            ans += value * 2;
            r -= half;
        }
        else {
            ans += value * 3;
            r -= half;
            c -= half;
        }
    }
    
    cout << ans << endl;
}

void soloution_2() {
    ans = recur(n, r, c);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    soloution_1();
    // soloution_2();
    
    return 0;
}