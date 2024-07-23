class Solution {
public:

    int setBits(int n){
        int cnt=0;
        while(n!=0){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int val=setBits(i);
            ans.push_back(val);
        }
        return ans;
    }
};