#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int n, int open, int close, string current, vector<string>& result) {
        // Base case: string length is 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Decision 1: Add '(' if we still have available open parentheses
        if (open < n) {
            backtrack(n, open + 1, close, current + '(', result);
        }

        // Decision 2: Add ')' if it won't exceed the number of open parentheses
        if (close < open) {
            backtrack(n, open, close + 1, current + ')', result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};