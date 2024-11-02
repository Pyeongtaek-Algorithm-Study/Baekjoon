#include <iostream>
#include <queue>

using namespace std;

int r, c;
char puzzle[21][21];
priority_queue<string, vector<string>, greater<string> > pq;

void input() {
    cin >> r >> c;
    for(int i = 0; i< r; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < c; j++) {
            puzzle[i][j] = str[j];
        }
    }
}

void solve() {
    string tmp;
    for(int i = 0; i < r; i++) {
        tmp = "";
        for(int j = 0; j < c; j++) {
            if(puzzle[i][j] != '#') tmp += puzzle[i][j];
            else {
                if(tmp.length() >= 2) pq.push(tmp);
                tmp = "";
            }
            if(j == c - 1 && tmp.length() >= 2) pq.push(tmp);
        }   
    }
    for(int i = 0; i < c; i++) {
        tmp = "";
        for(int j = 0; j < r; j++) {
            if(puzzle[j][i] != '#') tmp += puzzle[j][i];
            else {
                if(tmp.length() >= 2) pq.push(tmp);
                tmp = "";
            }
            if(j == r - 1 && tmp.length() >= 2) pq.push(tmp);
        }   
    }
    
    cout << pq.top() << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    
    return 0;
}