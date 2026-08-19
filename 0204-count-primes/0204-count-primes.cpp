class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // handle 2 separately, then sieve only odd numbers
        vector<char> isComposite(n, 0);
        int cnt = 1; // count 2

        for (long long i = 3; i < n; i += 2) {
            if (!isComposite[i]) {
                cnt++;
                for (long long j = i * i; j < n; j += 2 * i) {
                    isComposite[j] = 1;
                }
            }
        }

        return cnt;
    }
};