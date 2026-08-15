#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // Case 3: The array only contains 0s
        if (!hasNonZero) {
            return 0;
        }
        
        // Case 1: The total XOR is already non-zero
        if (totalXor != 0) {
            return nums.size();
        }
        
        // Case 2: The total XOR is 0, so remove exactly one non-zero element
        return nums.size() - 1;
    }
};