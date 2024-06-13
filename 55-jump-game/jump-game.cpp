class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(ans>=nums.size()-1){
                return true;
            }
            if(nums[i]==0 && ans==i){
                return false;
            }
            if(i+nums[i]>ans){
                ans=i+nums[i];
            }
        }
        return true;
    }
};