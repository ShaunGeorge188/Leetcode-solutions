class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();   // number of *distinct* chars that must be fully matched
        int formed = 0;                // how many distinct chars are currently fully matched
        unordered_map<char, int> windowCounts;

        int left = 0, minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < (int)s.length(); right++) {
            char c = s[right];
            windowCounts[c]++;

            if (need.count(c) && windowCounts[c] == need[c]) {
                formed++;
            }

            // window is valid — try shrinking from the left
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCounts[leftChar]--;
                if (need.count(leftChar) && windowCounts[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};