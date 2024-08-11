class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        // if source is not 0
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }
        // if size is 1 ie source is ans
        if (grid[0][0] == 0 && n == 1 && m == 1) {
            return 1;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        q.push({1, {0, 0}});
        // move in 8 directions
        vector<int> drow = {0, 1, -1, 0, 1, -1, 1, -1};
        vector<int> dcol = {1, 0, 0, -1, 1, 1, -1, -1};

        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // check the 8 direction adjacent nodes
            for (int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    dis + 1 < dist[nrow][ncol] && grid[nrow][ncol] == 0) {
                    dist[nrow][ncol] = dis + 1;
                    // when reached goal
                    if (nrow == n - 1 && ncol == m - 1) {
                        return dis + 1;
                    }
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};