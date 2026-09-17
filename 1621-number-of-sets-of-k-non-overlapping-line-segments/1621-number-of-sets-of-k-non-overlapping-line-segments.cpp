class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total_n = n + k - 1;
        int total_r = 2 * k;

        // Compute C(total_n, total_r) % MOD
        long long result = 1;
        for (int i = 1; i <= total_r; ++i) {
            result = (result * (total_n - i + 1)) % MOD;
            result = (result * modInverse(i, MOD)) % MOD;
        }

        return result;
    }

private:
    // Extended Euclidean Algorithm for Modular Multiplicative Inverse
    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long y = 0, x = 1;
        if (m == 1) return 0;
        while (a > 1) {
            long long q = a / m;
            long long t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return x;
    }
};