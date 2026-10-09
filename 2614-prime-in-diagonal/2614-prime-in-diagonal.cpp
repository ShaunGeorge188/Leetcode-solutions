class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int diagonalPrime(std::vector<std::vector<int>>& nums) {
        int max_prime = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Check main diagonal element
            int val1 = nums[i][i];
            if (val1 > max_prime && isPrime(val1)) {
                max_prime = val1;
            }

            // Check anti-diagonal element
            int val2 = nums[i][n - i - 1];
            if (val2 > max_prime && isPrime(val2)) {
                max_prime = val2;
            }
        }

        return max_prime;
    }
};