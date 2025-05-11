#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define LIM 100001

int n, nums[LIM] = { 0, };

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}

void solve() {
    stack<int> st;
    vector<char> push_pop;
    int cur = 1;
    
    for(int i = 0; i < n; i++) {
        int num = nums[i];
        while(cur <= num) {
            push_pop.push_back('+');
            st.push(cur++);
        }
        
        if(num == st.top()) {
            push_pop.push_back('-');
            st.pop();
        }
        else {
            cout << "NO" << '\n';
            exit(0);
        }
    }
    
    for(int i = 0; i < push_pop.size(); i++) cout << push_pop[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}