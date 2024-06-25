#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int dfs(vector<int> adj[], int node, vector<int>& depth, vector<bool>& visited) {
    if (visited[node]) {
        return depth[node];
    }
    visited[node] = true;
    int max_depth = 0;
    for (auto it : adj[node]) {
        max_depth = max(max_depth, dfs(adj, it, depth, visited));
    }
    depth[node] = max_depth + 1; 
    return depth[node];
}
int findMaxDepth(vector<int> adj[], int n) {
    vector<int> depth(n + 1, 0); 
    vector<bool> visited(n + 1, false); 

    int max_depth = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            max_depth = max(max_depth, dfs(adj, i, depth, visited));
        }
    }
    
    return max_depth;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++) {
        if (v[i] != -1) {
            adj[i + 1].push_back(v[i]);
        }
    }

    int maxDepth = findMaxDepth(adj, n);
    cout << maxDepth << endl;

    return 0;
}
