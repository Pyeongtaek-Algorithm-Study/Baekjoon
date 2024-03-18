#include <iostream>
#include <map>

using namespace std;

int n, m;
map<string, string> pw;
string domain, pass;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> domain >> pass;
        pw.insert({domain, pass});
    }
    while(m--) {
        cin >> domain;
        cout << pw[domain] << "\n";
    }
    return 0;
}