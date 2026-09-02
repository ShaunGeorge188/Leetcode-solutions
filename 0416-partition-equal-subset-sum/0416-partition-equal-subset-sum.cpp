class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // If the total sum is odd, it's impossible to divide it into two equal integers
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        
        // dp[i] will be true if a subset with sum 'i' can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true; // A sum of 0 is always possible (empty subset)
        
        for (int num : nums) {
            // Traverse backward to prevent using the same number multiple times
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};