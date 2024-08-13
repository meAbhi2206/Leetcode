class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create graph
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int Ntime = it.second;
                int adjN = it.first;
                if (time + Ntime < dist[adjN]) {
                    dist[adjN] = time + Ntime;
                    pq.push({dist[adjN], adjN});
                }
            }
        }

        // Find max distance from dist vector
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
