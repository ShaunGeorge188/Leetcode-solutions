class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = nums[i];

        for (int len = 2; len <= n; len++) {
            for (int low = 0; low + len - 1 < n; low++) {
                int high = low + len - 1;
                dp[low][high] = max(
                    nums[low]  - dp[low + 1][high],
                    nums[high] - dp[low][high - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};