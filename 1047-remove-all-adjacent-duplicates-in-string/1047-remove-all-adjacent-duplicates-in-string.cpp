class Solution {
public:
    string removeDuplicates(string s) {
        string st; // using string as a stack (has push_back/pop_back)
        
        for (char c : s) {
            if (!st.empty() && st.back() == c) {
                st.pop_back(); // cancel adjacent duplicate
            } else {
                st.push_back(c);
            }
        }
        
        return st;
    }
};