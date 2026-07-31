class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }
        int totalPushes = 0;

        sort(freq.rbegin(), freq.rend());

        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;
            int cost = (i / 8) + 1;
            totalPushes += cost * freq[i]; 
        }
        return totalPushes;       
    }
};