
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int center = 0; center < n; ++center) {
            // Count odd-length palindromes (single character center)
            count += expandAroundCenter(s, center, center);
            // Count even-length palindromes (two character center)
            count += expandAroundCenter(s, center, center + 1);
        }

        return count;
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;  // Found a palindrome
            left--;
            right++;
        }
        return count;
    }
};

