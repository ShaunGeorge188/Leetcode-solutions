#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        
        // 1. Calculate the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); ++i) {
            // Check if the current element continues the sequence (+1 from previous)
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break; // Sequence broken
            }
        }
        
        // 2. Store all elements in a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer >= prefixSum
        while (numSet.count(prefixSum)) {
            prefixSum++;
        }
        
        return prefixSum;
    }
};