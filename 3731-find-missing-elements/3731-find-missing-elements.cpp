class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        
        int min_val = nums[0];
        int max_val = nums[0];
        unordered_set<int> present_nums;
        
        // Find boundaries and populate the hash set in a single pass
        for (int num : nums) {
            present_nums.insert(num);
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        vector<int> missing;
        
        // Check every number in the range against the hash set
        for (int i = min_val; i <= max_val; ++i) {
            if (present_nums.find(i) == present_nums.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};