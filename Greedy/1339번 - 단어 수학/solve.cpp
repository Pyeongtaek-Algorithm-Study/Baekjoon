#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

map<char, int> m;
int N;
vector<string> str;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        int j = 0, tmp = 1;
        while(j<=str.length()-1) {
            m[str[j]] += pow(10,str.length()-j-1);
            j++;
        }
    }
    vector<pair<char, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    int sequence = 9;
    int ans = 0;
    for(auto it : v) {
        ans += it.second * sequence;
        sequence--;
    }
    cout << ans << "\n";
    return 0;
}
