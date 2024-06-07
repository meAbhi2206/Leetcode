class Solution {
public:
   int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

int atMost(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int res = 0;
    unordered_map<int, int> mpp;

    while (r < n) {
        mpp[nums[r]]++;
        while (mpp.size() > k) {
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0) {
                mpp.erase(nums[l]);
            }
            l++;
        }
        res += r - l + 1;
        r++;
    }

    return res;
}
};