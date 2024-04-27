// 11725번 - 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[100001];
int vis[100001];

void DFS(int k) {
    for(int i = 0; i < v[k].size(); i++) {
        int tmp = v[k][i];
        if(!vis[tmp]) {
            vis[tmp] = k;
            DFS(tmp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }

    DFS(1);
    
    for(int i = 2; i < n+1; i++) cout << vis[i] << "\n";
    
    return 0;
}