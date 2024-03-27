class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.length();
        stack<char> s;
        s.push(num[0]);
        for (int i = 1; i < n; i++) {
            while (!s.empty() && k > 0 && num[i] < s.top()) {
                k--;
                s.pop();
            }
            s.push(num[i]);
            if (s.size() == 1 && num[i] == '0') {
                s.pop();
            }
        }
        while (k > 0 && !s.empty()) {
            k--;
            s.pop();
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        if(ans.length()==0){
            return "0";
        }

        return ans;
    }
};
