#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    
    for(int i = 2; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) arr[i][j] = 1; 
            else if(j == i) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
  
    cout << arr[n-1][k-1];
    
    return 0;
}
