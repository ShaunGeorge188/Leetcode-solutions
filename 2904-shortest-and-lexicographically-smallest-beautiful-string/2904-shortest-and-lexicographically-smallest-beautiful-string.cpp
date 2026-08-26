class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = INT_MAX;
        string result = "";
        
        int left = 0, ones = 0;
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            
            // shrink if we have too many ones
            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }
            
            if (ones == k) {
                // trim leading zeros to get the tightest window
                while (s[left] == '0') left++;
                
                int len = right - left + 1;
                string candidate = s.substr(left, len);
                
                if (len < minLen) {
                    minLen = len;
                    result = candidate;
                } else if (len == minLen && candidate < result) {
                    result = candidate;
                }
            }
        }
        
        return result;
    }
};