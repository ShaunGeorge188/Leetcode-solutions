class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0;
        int insertions = 0;

        for (char c : s) {
            if (c == '(') {
                openNeeded++;
            } else {   // c == ')'
                if (openNeeded > 0) {
                    openNeeded--;   // matches an existing '('
                } else {
                    insertions++;   // no '(' to match, needs an inserted '('
                }
            }
        }

        return insertions + openNeeded;
    }
};