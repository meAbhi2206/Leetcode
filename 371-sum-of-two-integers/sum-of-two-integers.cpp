class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int Carry=a&b;
            a=a^b;
            b=Carry<<1;
        }
        return a;
    }
};