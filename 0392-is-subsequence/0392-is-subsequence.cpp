class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Found a match, move to the next character in s
            }
            j++; // Always move forward in t
        }
        
        // If we matched all characters of s, i will equal s.length()
        return i == s.length();
    }
};