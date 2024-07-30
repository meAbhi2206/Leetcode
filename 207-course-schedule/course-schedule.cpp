class Solution {
    private:
    bool checkDFS(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[] ){
        visited[node]=1;
        pathVisited[node]=1;

        //traverse
        for(auto it:adj[node]){
            if(!visited[it]){
                if(checkDFS(it,visited,pathVisited,adj)) return true;
            }
            else if(pathVisited[it]){
                return true;
            }
        }

        pathVisited[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        //converting matrix to list
        for(int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0], u = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(checkDFS(i, visited, pathVisited, adj)) {
                    return false; //cycle , canot complte
                }
            }
        }
        
        return true; //no cycle can complete
    }
};