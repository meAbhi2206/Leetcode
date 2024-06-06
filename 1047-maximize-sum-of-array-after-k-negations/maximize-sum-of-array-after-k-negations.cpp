class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n && nums[i]<0 && k>0 ;i++){
            nums[i]*=-1;
            k--;
        }
        int Min=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            Min=min(Min,nums[i]);
            sum+=nums[i];
        }
        if(k%2==1) sum-=Min*2;
        return sum;
    }
};