#include <vector>
#include <cmath>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int counts[3] = {0, 0, 0};
        
        // Count frequencies of remainders modulo 3
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        // If the number of 0s is even, they cancel out
        if (counts[0] % 2 == 0) {
            // Alice wins if she has both 1s and 2s available
            return counts[1] > 0 && counts[2] > 0;
        } 
        // If the number of 0s is odd, it flips the turn advantage
        else {
            // Alice needs a strong imbalance to force Bob to lose
            return std::abs(counts[1] - counts[2]) > 2;
        }
    }
};