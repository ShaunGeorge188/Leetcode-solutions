class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for(int num: nums2){
            while(!st.empty() && num > st.top()){
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for(int x: nums1) {
            result.push_back(nextGreater.count(x) ? nextGreater[x] : -1);
        }
        return result;
    }
};