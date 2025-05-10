#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2000000000

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int start = 0;
    int end = N-1;

    int min = INF;
    int ans[2];
    while(start < end) {
        int sum = v[start] + v[end];

        if(min > abs(sum)) {
            min = abs(sum);
            ans[0] = v[start];
            ans[1] = v[end];
            if(sum == 0) break;
        }
        if(sum < 0) start++;
        else end--;
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}