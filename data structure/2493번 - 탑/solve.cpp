#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N;
stack<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        while(!s.empty() && input > s.top().X) {
            s.pop();
        }
        if(s.empty()) cout << 0 << ' ';
        else cout << s.top().Y << ' ';
        s.push({input, i+1});
    }
    
    return 0;
}