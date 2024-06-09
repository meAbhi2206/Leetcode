class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i=mpp.begin();i !=mpp.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>results;
        while(!pq.empty()){
            results.push_back(pq.top().second);
            pq.pop();
        }
        return results;
    }
};