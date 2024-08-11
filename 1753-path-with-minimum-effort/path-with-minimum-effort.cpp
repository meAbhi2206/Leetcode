class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //{diff,{r,c}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        //4 directions
        vector<int>drow= {-1, 0, 1, 0};
        vector<int>dcol= {0, 1, 0, -1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // Checking validity of the cell.
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                {
                    // Effort =max(differences between the heights of the node and its adjacent nodes)
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    
                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};