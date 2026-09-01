class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int p = 2; p < n; ++p){
            dp[p] = max(dp[p - 1], nums[p] + dp[p - 2]);
        }

        return dp[n - 1];
    }
};