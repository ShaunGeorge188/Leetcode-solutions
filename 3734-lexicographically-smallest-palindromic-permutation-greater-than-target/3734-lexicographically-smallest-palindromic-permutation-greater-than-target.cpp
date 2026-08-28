#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int odds = 0;
        string mid_char = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odds++;
                mid_char = string(1, i + 'a');
                freq[i]--; // Remove one to leave an even count
            }
        }
        
        if (odds > 1) {
            return "";
        }
        
        vector<int> half_freq(26, 0);
        for (int i = 0; i < 26; i++) {
            half_freq[i] = freq[i] / 2;
        }
        
        int m = n / 2;
        vector<string> candidates;
        
        vector<int> current_avail = half_freq;
        for (int i = 0; i <= m; i++) {
            if (i == m) {
                // Try matching the first half completely
                bool can_match = true;
                vector<int> temp_avail = half_freq;
                for (int j = 0; j < m; j++) {
                    if (temp_avail[target[j] - 'a'] == 0) {
                        can_match = false;
                        break;
                    }
                    temp_avail[target[j] - 'a']--;
                }
                
                if (can_match) {
                    string half = target.substr(0, m);
                    string rev_half = half;
                    reverse(rev_half.begin(), rev_half.end());
                    string P = half + mid_char + rev_half;
                    if (P > target) {
                        candidates.push_back(P);
                    }
                }
                break;
            }
            
            // Can we match up to i - 1?
            if (i > 0) {
                if (current_avail[target[i - 1] - 'a'] == 0) {
                    break; // If we can't even match the prefix up to i-1, we stop.
                }
                current_avail[target[i - 1] - 'a']--;
            }
            
            // Try to pick a character greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (current_avail[c] > 0) {
                    string half = target.substr(0, i);
                    half += (char)(c + 'a');
                    
                    vector<int> temp_avail = current_avail;
                    temp_avail[c]--;
                    
                    // Fill the rest of the first half with the smallest available characters
                    for (int j = 0; j < 26; j++) {
                        while (temp_avail[j] > 0) {
                            half += (char)(j + 'a');
                            temp_avail[j]--;
                        }
                    }
                    
                    string rev_half = half;
                    reverse(rev_half.begin(), rev_half.end());
                    string P = half + mid_char + rev_half;
                    
                    candidates.push_back(P);
                    break; // Only need the smallest larger character to minimize the string
                }
            }
        }
        
        if (candidates.empty()) {
            return "";
        }
        
        string ans = candidates[0];
        for (const string& cand : candidates) {
            if (cand < ans) {
                ans = cand;
            }
        }
        
        return ans;
    }
};