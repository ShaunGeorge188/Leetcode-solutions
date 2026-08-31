#include <vector>

class Solution {
public:
    int smallestEqual(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 10 == nums[i]) {
                return i; // First match is guaranteed to be the smallest index
            }
        }
        return -1; // No index satisfied the condition
    }
};