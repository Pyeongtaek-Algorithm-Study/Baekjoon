#include <iostream>

using namespace std;

pair<int, int> p[101];
int arr[101][100001];

int main() 
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for(int i=1;i <=n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            arr[i][j] = arr[i-1][j];
            if(p[i].first <= j) 
                arr[i][j] = max(p[i].second + arr[i-1][j-p[i].first], arr[i][j]);
        }
    }
    cout << arr[n][k];
    return 0;
}