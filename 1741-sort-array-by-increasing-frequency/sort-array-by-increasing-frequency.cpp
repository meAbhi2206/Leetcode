class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto i: nums) {
            mpp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i=mpp.begin();i!=mpp.end();i++){
            pq.push({-i->second,i->first});
        }

        vector<int> results;
        while(!pq.empty()){
            for(int i=0;i<-(pq.top().first);i++){
                results.push_back(pq.top().second);
            }
            pq.pop();
        }
        return results;
    }
};