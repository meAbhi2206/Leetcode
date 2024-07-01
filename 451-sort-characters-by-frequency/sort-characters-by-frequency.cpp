class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty()){
            for(int i=0;i<(pq.top().first);i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};