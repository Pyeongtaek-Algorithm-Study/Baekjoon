#include<bits/stdc++.h>

using namespace std;

string S;
int cnt[2]={0,0};

int main() 
{
    cin >> S;
    if(S[0]== '0') cnt[0]++;
    else cnt[1]++;
    
    for(int i=1;i < S.length(); i++) {
        if(S[i] != S[i-1]) {
            if(S[i]=='0') cnt[0]++;
            else cnt[1]++;
        }
    }
    int ans = min(cnt[0], cnt[1]);
    cout << ans;
  
    return 0;
}
