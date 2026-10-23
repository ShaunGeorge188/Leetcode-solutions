class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string best = "";
        int n = s.size();

        for(int i = 0; i < n; i++){
            int ones = 0;
            for(int j = i; j < n; j++){
                if(s[j] == '1') ones++;

                if(ones == k){
                    string cand = s.substr(i, j - i + 1);
                    if(best.empty() || cand.size() < best.size() || (cand.size() == best.size() && cand < best)){
                        best = cand;
                    }
                    break;
                }
            }
        }
        return best;
    }
};