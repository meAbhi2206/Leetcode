class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       //create adj list
        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});// 0->{1,100}
        }

        //{stop,{node,dist}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            // traverse adj nodes and update weights
            for(auto x: adj[node]){
                int adjNode = x.first;
                int edW = x.second;

                //relax dist 
                if (dis + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = dis + edW;
                    q.push({stops + 1, {adjNode, dis + edW}});
                }
            }
        }
        //if cannot reach 
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};