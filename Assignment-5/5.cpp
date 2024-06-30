                               // didnt got sol on my own saw from internet     
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> eff(n, vector<int>(m, 1e9));
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, 
        pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        eff[0][0] = 0;
        pq.push({0, {0, 0}});
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while (!pq.empty()) {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == n-1 && col == m-1)
                return effort;
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max (effort, abs(heights[nrow][ncol] - heights[row][col]));
                    if (newEffort < eff[nrow][ncol]) {
                        eff[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}}); 
                    }
                }
            }
        }
        return 0;
    }
};