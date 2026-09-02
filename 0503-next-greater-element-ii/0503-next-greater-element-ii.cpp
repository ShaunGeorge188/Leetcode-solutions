class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stores the actual values
        
        // Loop backward through the virtually doubled array
        for (int i = 2 * n - 1; i >= 0; --i) {
            // 1. Maintain a strictly decreasing stack
            // Pop any element that is smaller than or equal to the current element
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            
            // 2. Only record the answer if we are on the original part of the array
            if (i < n) {
                if (!st.empty()) {
                    result[i] = st.top();
                }
            }
            
            // 3. Push the current element onto the stack for future numbers to compare against
            st.push(nums[i % n]);
        }
        
        return result;
    }
};