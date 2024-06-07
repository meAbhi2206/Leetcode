class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int N = t.size();
        vector<int> map(128, 0);
        int l = 0;
        int r = 0;
        int minL = INT_MAX;
        int head = 0;
        for (int i = 0; i < N; i++) {
            map[t[i]]++;
        }
        while (r < n) {
            if (map[s[r]] > 0) {
                N--;
            }
            map[s[r]]--;
            r++;

            while (N == 0) {
                if (r - l < minL) {
                    minL = r - l;
                    head = l;
                }
                map[s[l]]++;
                if(map[s[l]]==1){
                    N++;
                }
                l++;
            }
        }
        return minL == INT_MAX ? "" : s.substr(head, minL);
    }
};