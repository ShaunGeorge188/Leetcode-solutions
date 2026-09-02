class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If balance is > 0, this is an inner parenthesis
                if (balance > 0) {
                    result += c;
                }
                balance++; // Increase depth
            } else { // c == ')'
                balance--; // Decrease depth
                // If balance is > 0, this is an inner parenthesis
                if (balance > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};