// Using DFS cycle detection method
class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited,
             vector<int>& PathVis, vector<int>& Check) {
        visited[node] = 1;
        PathVis[node] = 1;
        Check[node] = 0;
        for (auto it : graph[node]) {
            if (!visited[it]) {
                if (dfs(it, graph, visited, PathVis,Check)) {
                    return true;
                }
            } else if (PathVis[it]) {
                return true;
            }
        }
        Check[node] = 1;
        PathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> visited(V, 0);
        vector<int> PathVis(V, 0);
        vector<int> Check(V, 0);
        vector<int> safeNode;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, PathVis, Check);
            }
        }
        for (int i = 0; i < V; i++) {
            if (Check[i] == 1) {
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }

};