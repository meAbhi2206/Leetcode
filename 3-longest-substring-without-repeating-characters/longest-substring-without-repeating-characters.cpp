class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.size();
    if (n == 0)
        return 0;
    int maxL = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<char> st;
        for (int j = i; j < n; j++) {
            if (st.find(s[j]) != st.end()) {
                break;
            }
            st.insert(s[j]);
            maxL = max(maxL, j - i + 1);  // Correctly calculate the length of the current substring
        }
    }
    return maxL;
    }
};