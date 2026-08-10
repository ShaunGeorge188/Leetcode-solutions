#include <vector>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] represents if the current player can win starting with i stones
        vector<bool> dp(n + 1, false);
        
        // Base case: dp[0] = false. If a player starts with 0 stones, they lose.
        
        for (int i = 1; i <= n; ++i) {
            // Try removing all possible non-zero square numbers
            for (int k = 1; k * k <= i; ++k) {
                // If taking k*k stones leaves the opponent in a losing state (false),
                // then the current player can force a win.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Found a winning strategy for i stones, skip checking others
                }
            }
        }
        
        return dp[n];
    }
};