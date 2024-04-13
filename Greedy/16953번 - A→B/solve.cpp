#include<bits/stdc++.h>

using namespace std;

int A, B;
int cnt = 0, tmp;

int main() 
{
    cin >> A >> B;
    int result = -1;
    tmp = B;
    while(A<=tmp) {
        if(A==tmp) {
            cout << cnt+1;
            return 0;
        }
        if(tmp % 10 == 1) {
            tmp /= 10;
            cnt++;
        }
        else if(tmp % 2 == 0) {
            tmp /= 2;
            cnt++;
        }
        else {
            break;
        }
    }
    cout << result;
    
    return 0;
}
