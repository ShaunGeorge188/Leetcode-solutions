class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suffix(n + 1, 0);
        int j = m - 1;
        for(int i = n - 1; i >= 0; i--){
            suffix[i] = suffix[i + 1];
            if(j >= 0 && word1[i] == word2[j]){
                suffix[i]++;
                j--;
            }
        }

        vector<int> result;
        int idx2 = 0;
        bool usedChange = false;

        for(int i = 0; i < n && idx2 < m; i++){
            if(word1[i] == word2[idx2]){
                result.push_back(i);
                idx2++;
            }else if(!usedChange && suffix[i + 1] >= m - idx2 - 1){
                result.push_back(i);
                idx2++;
                usedChange = true;
            }
        }

        if(idx2 == m) return result;
        return {};
    }
};