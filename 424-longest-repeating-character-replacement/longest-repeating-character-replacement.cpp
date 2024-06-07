class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int maxL = 0;
        int maxF = 0;
        int len=r-l+1;
        vector<int> hash(26, 0);
        while (r < n) {
            hash[s[r] - 'A']++;
            maxF = *max_element(hash.begin(), hash.end());
            while (r - l + 1 - maxF > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            maxL = max(maxL, r - l + 1);
            r++;
        }
        return maxL;
    }
};