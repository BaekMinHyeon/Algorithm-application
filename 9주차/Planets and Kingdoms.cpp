#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
stack<int> st;
int kingdom = 0; // maximal strongly connected component
 
//DFS Traversal of reversed graph
void DFS(int node, vector<vector<int>>& a, vector<int>& b) {
    b[node] = 1;
    for (int child : a[node]) {
        if (b[child] != 1) {
            DFS(child, a, b);
        }
    }
    st.push(node);
}
 
//DFS traversal of an original graph
void DFS2(int node, vector<vector<int>>& a, vector<int>& b, vector<int>& c) {
    b[node] = 1;
    c[node] = kingdom;
    for (int child : a[node]) {
        if (b[child] != 1) {
            DFS2(child, a, b, c);
        }
    }
}
 
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> arr1(n);
    vector<vector<int>> arr2(n);
    vector<int> visited1(n);
    vector<int> visited2(n);
    vector<int> count(n);
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        arr1[a].push_back(b);
        arr2[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if(visited1[i] != 1)
            DFS(i, arr2, visited1);
    }
    while (!st.empty()) {
        int k = st.top();
        st.pop();
        if (visited2[k] != 1) {
            kingdom++;
            DFS2(k, arr1, visited2, count);
        }
 
    }
    cout << kingdom << endl;
    for (int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    return 0;
}