class Solution {
public:
    string countAndSayHelper(string s) {
        string result = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int count = 1;

            while (i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }

            result += to_string(count) + s[i];
        }

        return result;
    }

    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++) {
            result = countAndSayHelper(result);
        }

        return result;
    }
};