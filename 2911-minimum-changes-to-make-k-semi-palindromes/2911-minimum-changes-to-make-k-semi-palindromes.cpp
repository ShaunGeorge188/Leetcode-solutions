
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute minimum changes for every substring.
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                // Try every proper divisor.
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Process each group.
                    for (int offset = 0; offset < d; offset++) {
                        int left = l + offset;

                        // Correct calculation of the last
                        // element in this group.
                        int right = l + offset +
                                    ((len - 1 - offset) / d) * d;

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][j] = minimum changes to divide
        // first j characters into exactly i parts.
        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int j = 2 * parts; j <= n; j++) {
                for (int p = 2 * (parts - 1); p <= j - 2; p++) {

                    if (dp[parts - 1][p] == INF) {
                        continue;
                    }

                    dp[parts][j] = min(
                        dp[parts][j],
                        dp[parts - 1][p] + cost[p][j - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
