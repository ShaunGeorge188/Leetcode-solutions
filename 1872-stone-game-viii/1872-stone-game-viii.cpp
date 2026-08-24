#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums in-place
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Base case: Taking all stones (index n-1)
        int dp = stones[n - 1];
        
        // Process backward from n-2 down to index 1 (Alice must pick x > 1 stones)
        for (int i = n - 2; i > 0; --i) {
            dp = std::max(dp, stones[i] - dp);
        }
        
        return dp;
    }
};