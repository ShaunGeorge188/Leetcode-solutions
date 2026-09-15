#include <string>
#include <algorithm>

class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // Tracks the end index of the previous selected palindrome

        for (int i = 0; i < n; ++i) {
            // Check odd-length center (expand to length k or k+1)
            // Check even-length center (expand to length k or k+1)
            for (int len : {k, k + 1}) {
                int left = i;
                int right = i + len - 1;
                
                // Fast boundary check before verifying palindrome property
                if (right >= n) continue;

                // Expand outward from center to check if s[left..right] is a palindrome
                bool is_palindrome = true;
                int l = left, r = right;
                while (l < r) {
                    if (s[l] != s[r]) {
                        is_palindrome = false;
                        break;
                    }
                    l++;
                    r--;
                }

                // If valid and doesn't overlap with the last selected palindrome
                if (is_palindrome && left > last_end) {
                    count++;
                    last_end = right; // Greedily take this palindrome
                    break;           // Move on to next possible starting index
                }
            }
        }

        return count;
    }
};