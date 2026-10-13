class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;
        squares.reserve(nums.size());
        
        // Square each number (using 1LL to prevent integer overflow)
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }
        
        // Sort the squares in descending order
        sort(squares.begin(), squares.end(), greater<long long>());
        
        long long score = 0;
        int k = (nums.size() + 1) / 2; // Number of elements to add
        
        // Add the largest squares (even indices in the optimal arrangement)
        for (int i = 0; i < k; ++i) {
            score += squares[i];
        }
        
        // Subtract the smallest squares (odd indices in the optimal arrangement)
        for (int i = k; i < squares.size(); ++i) {
            score -= squares[i];
        }
        
        return score;
    }
};