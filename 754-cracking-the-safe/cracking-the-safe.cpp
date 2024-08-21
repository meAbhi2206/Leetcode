class Solution {
    private:
    void dfs(string node, int k, unordered_set<string>& seen, string& ans) {
        for (int x = 0; x < k; ++x) {
            string nei = node + to_string(x);
            if (seen.find(nei) == seen.end()) {  // If nei not in seen
                seen.insert(nei);  // Mark nei as seen
                dfs(nei.substr(1), k, seen, ans);  // Recursive call with the next state
                ans += to_string(x);  // Append x to the answer
            }
        }
    }
public:
    string crackSafe(int n, int k) {
         unordered_set<string> seen;
        string ans;
        string start(n - 1, '0');  // Start with n-1 zeros
        dfs(start, k, seen, ans);
        ans += start;  // Handle the wrap-around
        return ans;
    }
};