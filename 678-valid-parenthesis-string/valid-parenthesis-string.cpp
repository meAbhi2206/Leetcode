class Solution {
public:
    bool checkValidString(string s) {
        int l=0;
        int r=0;
        for(char i:s){
            if(i=='('){
                l++;
                r++;
            }
            else if(i==')'){
                l--;
                r--;
            }
            else{
                l--;
                r++;
            }
            if(r<0) return false;
            if(l<0) l=0;
        }
        return l==0;
    }
};