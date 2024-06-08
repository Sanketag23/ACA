class Solution {
public:
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();
        vector<int> color(n, -1); 
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (BFS(gph, color, i) == false)
                    return false;
            }
        }
        return true;
    }
private:
    bool BFS(vector<vector<int>>& gph, vector<int>& color, int& start) {
        color[start] = 0;
        queue<int> Q; Q.push(start);

        while (!Q.empty()) {
            int node = Q.front(); Q.pop();
            for (auto& adjNode : gph[node]) {
                if (color[adjNode] == color[node]) {
                    return false;
                } else if (color[adjNode] == -1) {
                    color[adjNode] = 1 - color[node];
                    Q.push(adjNode);
                }
            }
        }
        return true;
    }
};