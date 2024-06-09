class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        int m=points[0].size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int dist=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            int x=points[i][0];
            int y=points[i][1];

            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>result;
        while(!pq.empty()){
            pair<int,int>p=pq.top().second;
            result.push_back({p.first,p.second});
            pq.pop();
        }
        return result;
    }
};