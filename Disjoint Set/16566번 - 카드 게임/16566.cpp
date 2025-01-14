#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
vector<int> v;
int parent[4000001];

void input() {
    cin >> n >> m >> k;
    
	for(int i = 0, a; i < m; i++) {
		cin >> a;
		v.push_back(a);
		parent[i] = i;
	}
	
}

int Find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if(a != b) parent[b] = a;
}

void solve() {
    sort(v.begin(), v.end());
	for(int i = 0, a; i < k; i++) {
		cin >> a;
		int idx = Find(upper_bound(v.begin(), v.end(), a) - v.begin());
		cout << v[idx] << '\n';
		Union(idx + 1, idx);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    input();
    solve();
    
    return 0;
}