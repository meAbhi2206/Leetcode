class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // No primes less than 2

        // Initialize an array with all true
        vector<int> Prime(n, 1);
        Prime[0] = 0;
        Prime[1] = 0;
        
        for (int i = 2; i * i < n; i++) {
            if (Prime[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    Prime[j] = 0; // Setting all multiples of i as 0 (false)
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (Prime[i] == 1) {
                count++;
            }
        }
        
        return count;
    }
};
