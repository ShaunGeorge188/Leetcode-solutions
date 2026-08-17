#include <vector>
#include <algorithm>

class Solution {
public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Step 1: Compute prefix sums for O(1) range sum queries
        std::vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        // Step 2: Initialize memoization table with -1
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
        
        // Step 3: Start DFS from the full array range
        return dfs(0, n - 1, prefix, memo);
    }
    
private:
    int dfs(int left, int right, const std::vector<int>& prefix, std::vector<std::vector<int>>& memo) {
        // Base case: 1 stone left, score is 0
        if (left >= right) return 0;
        
        // Return cached result if already computed
        if (memo[left][right] != -1) return memo[left][right];
        
        int max_score = 0;
        
        // Try all possible split points
        for (int i = left; i < right; ++i) {
            int left_sum = prefix[i + 1] - prefix[left];
            int right_sum = prefix[right + 1] - prefix[i + 1];
            
            if (left_sum < right_sum) {
                // Bob throws away the right part
                max_score = std::max(max_score, left_sum + dfs(left, i, prefix, memo));
            } else if (left_sum > right_sum) {
                // Bob throws away the left part
                max_score = std::max(max_score, right_sum + dfs(i + 1, right, prefix, memo));
            } else {
                // Sums are equal, Alice gets to choose the optimal path
                max_score = std::max({
                    max_score, 
                    left_sum + dfs(left, i, prefix, memo), 
                    right_sum + dfs(i + 1, right, prefix, memo)
                });
            }
        }
        
        // Cache and return the result
        return memo[left][right] = max_score;
    }
};