class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3){
            return n;
        }

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int p = 3; p <= n; p++){
            dp[p] = dp[p-1] + dp[p-2];
        }
        return dp[n];
    }
};