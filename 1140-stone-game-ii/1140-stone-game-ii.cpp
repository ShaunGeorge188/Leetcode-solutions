#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // suffixSum[i] stores the total number of stones from pile i to the end
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // memo[i][m] stores the max stones a player can get starting at index i with given M
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, suffixSum, memo);
    }

private:
    int solve(int i, int m, const vector<int>& piles, const vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();
        
        // Base Case 1: No more piles left
        if (i >= n) return 0;
        
        // Base Case 2: We can take all remaining piles
        if (i + 2 * m >= n) return suffixSum[i];

        // Return memoized result if already computed
        if (memo[i][m] != -1) return memo[i][m];

        int maxStones = 0;
        
        // Try all possible moves: take X piles where 1 <= X <= 2M
        for (int x = 1; x <= 2 * m; ++x) {
            // The stones the current player gets is the total remaining stones 
            // MINUS the maximum stones the opponent can get from the remaining piles.
            int opponentScore = solve(i + x, max(m, x), piles, suffixSum, memo);
            int currentScore = suffixSum[i] - opponentScore;
            
            maxStones = max(maxStones, currentScore);
        }

        return memo[i][m] = maxStones;
    }
};