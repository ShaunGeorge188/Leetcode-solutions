#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the maximum index we can reach, fail
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest index we can reach from here
            maxReach = max(maxReach, i + nums[i]);
            
            // Early exit if we can already reach or exceed the last index
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};