class Solution {
public:
    int checkValid(const string& s, int i, const vector<int>& first, const vector<int>& last) {
        int right = last[s[i] - 'a'];
        
        for (int j = i; j <= right; ++j) {
            // If a character inside the current bounds has its first occurrence 
            // BEFORE our starting index 'i', we would have to expand left.
            // This invalidates 'i' as a valid starting point for a minimal substring.
            if (first[s[j] - 'a'] < i) {
                return -1; 
            }
            // Expand the right boundary if a character appears later in the string
            right = max(right, last[s[j] - 'a']);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // 1. Record the first and last occurrence of every character
        for (int i = 0; i < s.length(); ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        vector<string> res;
        int right = -1; // Tracks the end index of the last added substring

        // 2. Iterate through the string to find and greedily select valid intervals
        for (int i = 0; i < s.length(); ++i) {
            // Only attempt to start a substring at a character's FIRST occurrence
            if (i == first[s[i] - 'a']) {
                int new_right = checkValid(s, i, first, last);
                
                if (new_right != -1) {
                    // If this valid substring starts AFTER the last added one ends
                    if (i > right) {
                        res.push_back(s.substr(i, new_right - i + 1));
                    } 
                    // If it starts BEFORE the last added one ends, it is guaranteed 
                    // to be entirely contained within it. Greedily replace the larger
                    // previous substring with this smaller, valid one.
                    else {
                        res.back() = s.substr(i, new_right - i + 1);
                    }
                    right = new_right;
                }
            }
        }
        return res;
    }
};