class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end());
        
        // O(1) space trick: numbers are bounded 0-50
        vector<int> freq(51, 0);
        for (int num : nums) freq[num]++;
        
        if (k == 1) {
            int max_val = -1;
            for (int i = 0; i <= 50; i++) {
                if (freq[i] == 1) max_val = max(max_val, i);
            }
            return max_val;
        }
        
        int res = -1;
        if (freq[nums[0]] == 1) res = max(res, nums[0]);
        if (freq[nums[n-1]] == 1) res = max(res, nums[n-1]);
        
        return res;
    }
};