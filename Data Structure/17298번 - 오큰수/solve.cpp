// 17298번: 오큰수
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
stack<int> s;
int arr[1000001];
int ans[1000001];

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
      int tmp;
      cin >> arr[i];
      ans[i] = -1;
  }
}

void solve() {
  s.push(0);
  
  for(int i = 0; i < n; i++) {
    while(!s.empty() && (arr[s.top()] < arr[i])) {
      ans[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }
    
  for(int i = 0; i < n; i++) 
    cout << ans[i] << " ";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  input();
  solve();
  
  return 0;
}