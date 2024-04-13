#include <bits/stdc++.h>

using namespace std;

int N;
string str;
unordered_map<string, int> input_m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        input_m[str] = i+1;
    }
    
    int out_sequence[N];
    int pass = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        out_sequence[i] = input_m[str];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(out_sequence[i] > out_sequence[j]) {
                pass++; 
                break;
            }
        }
    }
    
    cout << pass;
    return 0;
}
