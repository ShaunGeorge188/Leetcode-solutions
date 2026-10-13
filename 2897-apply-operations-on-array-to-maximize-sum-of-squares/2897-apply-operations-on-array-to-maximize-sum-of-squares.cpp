#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> bitCount(30, 0);

        // Step 1: Count set bits at each position
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSum = 0;

        // Step 2: Form the top k largest possible numbers
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i < 30; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }

        return totalSum;
    }
};