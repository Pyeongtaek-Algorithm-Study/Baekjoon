#include<bits/stdc++.h>

using namespace std;

int N, M;
int b, tmp;
int m = INT_MAX;

bool check(int i, bool broke[]) {
    string ss = to_string(i);
    for(int i = 0; i < ss.length(); i++) {
        if(broke[ss[i] - '0']) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    bool broke[10] = { 0, };
    for(int i = 0; i < M; i++) {
        cin >> b;
        broke[b] = 1;
    }
    string str = to_string(N);
    m = abs(N - 100);
    int i = 0;
    while(i < 1000001) {
        if(check(i, broke)) {
            tmp = abs(N - i) + to_string(i).length();
            m = min(m, tmp);
        }
        i++;
    }
    cout << m;
    
    return 0;
}