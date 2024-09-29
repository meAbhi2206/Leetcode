class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum=0;
        for(int i=0;i<shifts.size();i++){
            sum+=shifts[i];
        }

        for(int i=0;i<shifts.size();i++){
            s[i]='a'+(s[i]-'a'+sum)%26;
            sum-=shifts[i];
        }
        return s;
    }
};