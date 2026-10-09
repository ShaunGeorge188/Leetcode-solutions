class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;   // unmatched '('
        int ans = 0;    // insertions made

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {   // s[i] == ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;        // consume the full "))"
                } else {
                    ans++;      // lone ')', insert one more ')' to complete the pair
                }

                if (open > 0) {
                    open--;     // matched with an existing '('
                } else {
                    ans++;      // no '(' available, insert one
                }
            }
        }

        return ans + 2 * open;  // each leftover '(' needs "))"
    }
};