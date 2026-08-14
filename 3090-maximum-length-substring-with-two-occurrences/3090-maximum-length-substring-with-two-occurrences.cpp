class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> count(26, 0);

        int left = 0,  maxlen = 0;

        for(int right = 0; right < n; right++){
            count[s[right] - 'a']++;

            while(count[s[right] - 'a'] > 2){
                count[s[left] -  'a']--;
                left++;
            }

            maxlen =  max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};