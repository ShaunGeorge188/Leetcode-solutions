
class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int end = start + k;
                int descents = 0;
                int mn = nums[start];
                int mx = nums[start];

                // Count descents inside the block
                for (int i = start; i + 1 < end; i++) {
                    if (nums[i] > nums[i + 1])
                        descents++;

                    mn = min(mn, nums[i + 1]);
                    mx = max(mx, nums[i + 1]);
                }

                // Include the circular boundary
                if (nums[end - 1] > nums[start])
                    descents++;

                // The block must be cyclically non-decreasing
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Sorted blocks must join in non-decreasing order
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};
