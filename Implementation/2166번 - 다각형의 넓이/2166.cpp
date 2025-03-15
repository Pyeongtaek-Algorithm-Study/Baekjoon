#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

typedef long long ll;

int n;
vector<pair<double, double> > v;

void input() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
}

void solve() {
    double total = 0.0;
    
    for(int i = 2; i < n; i++) {
        total += (v[0].X * v[i - 1].Y) + (v[i - 1].X * v[i].Y) + (v[i].X * v[0].Y)
                -(v[i - 1].X * v[0].Y) - (v[i].X * v[i - 1].Y) - (v[0].X * v[i].Y);
    }
    
    total = abs(total) / 2;
    
    cout << fixed;
    cout.precision(1);
    
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}