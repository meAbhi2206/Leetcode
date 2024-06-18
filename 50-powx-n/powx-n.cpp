class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -nn;

        while (nn > 0) {
            if (nn & 1) {
                ans = ans * x;
            }
            x = x * x;
            nn = nn >> 1;
        }

        if (n < 0)
            ans = 1.0 / ans;
        return ans;
    }
};