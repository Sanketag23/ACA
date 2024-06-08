

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        bool visited[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }
        
        std::pair<int, int> start = std::make_pair(sr, sc);
        visited[start.first][start.second] = true;
        queue<pair<int, int>> q;
        q.push(start);

        vector<vector<int>> prevstep = grid;

        int originalColor = grid[sr][sc];
        prevstep[sr][sc] = color;

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
                if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                    continue;
                if (grid[v.first][v.second] != originalColor)
                    continue;
                if (visited[v.first][v.second])
                    continue;
                visited[v.first][v.second] = true;
                prevstep[v.first][v.second] = color;
                q.push(v);
            }
        }
        return prevstep;
    }
};
