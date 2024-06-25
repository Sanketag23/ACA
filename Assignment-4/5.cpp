                   // didnt got on my own tried to understand the solution and code 
#include <vector>
#include <algorithm>
using namespace std;
                              
class Solution {
public:
    void APUtil(int u, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap) {
        static int time = 0;
        int children = 0;

        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                APUtil(v, adj, visited, disc, low, parent, ap);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }

                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            }
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<int> parent(V, -1);
        vector<bool> ap(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                APUtil(i, adj, visited, disc, low, parent, ap);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) {
            return {-1};
        }

        return result;
    }
};