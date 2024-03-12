#include <iostream>

using namespace std;

int n;
pair<char, char> tree[26];

void input() {
    cin >> n;
    char root, left, right;
    for(int i = 0; i < n; i++) {
        cin >> root >> left >> right;
        tree[root - 'A'].first = left;
        tree[root - 'A'].second = right;
    }
}

void preorder(char node) {
    cout << node;
    int seq = node - 'A';
    if(tree[seq].first != '.') preorder(tree[seq].first);
    if(tree[seq].second != '.') preorder(tree[seq].second);
}

void inorder(char node) {
    int seq = node - 'A';
    if(tree[seq].first != '.') inorder(tree[seq].first);
    cout << node;
    if(tree[seq].second != '.') inorder(tree[seq].second);
}

void postorder(char node) {
    int seq = node - 'A';
    if(tree[seq].first != '.') postorder(tree[seq].first);
    if(tree[seq].second != '.') postorder(tree[seq].second);
    cout << node;
}


void solve() {
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}