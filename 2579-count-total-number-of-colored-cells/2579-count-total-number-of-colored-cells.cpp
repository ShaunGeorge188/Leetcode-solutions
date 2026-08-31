class Solution {
public:
    long long coloredCells(int n) {
        // Cast to long long to prevent integer overflow for 1 <= n <= 10^5
        return 1LL + 2LL * n * (n - 1);
    }
};